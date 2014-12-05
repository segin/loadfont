/* loadfont - Utility to temporarily load a font on Windows.
 * Copyright (C) 2014 Kirn Gill <segin2005@gmail.com>
 * 
 * vim: ts=4 sw=4 ai
 * 
 * See LICENSE for copyright licencing details. 
 */ 

#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	LPWSTR *arglist;
	int nargs;
	int i;
	int total;

	arglist = CommandLineToArgvW(GetCommandLineW(), &nargs);
	if(arglist == NULL) { 
		wprintf(L"CommandLineToArgvW failed.\n");
		return(1);
	} else { 
		for(i = 0; i < nargs; i++) { 
			// Why not use i? .otf files can contain multiple fonts per file.
			total += AddFontResourceW(arglist[i]);
		};
	}
	wprintf(L"Loaded %d fonts.\n", total);
	LocalFree(arglist);
	return(0);
}

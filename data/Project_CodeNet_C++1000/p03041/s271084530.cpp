#include <stdio.h>
#include <string.h>

int main(){
	
	char name [55] ;
	int Fs, Sn ;
	
	scanf ("%d %d", &Fs, &Sn);
	scanf ("%s", &name);
	
	int Th = Sn-1 ;
	
	int X = name[Th] + 32;
	name[Th]= X;
	
	printf ("%s", name);
	
	return 0 ;
}

//  \N JANGAN LUPA!!!!!
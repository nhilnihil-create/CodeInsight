#include <stdio.h>

int main (){
	int x,y;
	scanf ("%d %d",&x, &y );
	char s[x];
	scanf ("%s", &s);
	s[y-1]=s[y-1]+32;
	printf ("%s", s);
	
	
	
	
	
	return 0;
}
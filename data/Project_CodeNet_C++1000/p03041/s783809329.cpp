#include <stdio.h>

int main(){
	int x , y;
	char s [100];
	scanf ("%d %d", &x , &y);
	scanf ("%s", s ) ;
	if (s[y-1] >= 'A' && s[y-1] <= 'Z'){
		s[y-1] = s[y-1]+32;
	}
	printf ("%s",s);
	
	return 0;
}
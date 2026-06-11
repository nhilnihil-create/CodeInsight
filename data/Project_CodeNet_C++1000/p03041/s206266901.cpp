#include <stdio.h>
int main() {
	int n ;
	int k ;
	scanf("%d %d",&n, &k);
	char s[n+2];
	scanf("%s",s);
		s[k-1]+=32;
	printf("%s\n",s);
		
return 0;
}

#include <stdio.h>

char s[11];

int main()
{	 
	int ans = 0, i;
	
	scanf("%s", s);
	for(i = 0; s[i]; i++) ans += s[i] - 48;
	if(ans == 1) ans = 10;
	printf("%d\n", ans);
		
	return 0;
}
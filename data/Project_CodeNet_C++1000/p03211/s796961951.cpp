#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int l, n, i, d, min, temp;
	char s[10];
	while(~scanf("%s", s))
	{
		l=strlen(s);
		min = 10000;
		for(i=2; i<l; i++)
		{
			n = 100*(s[i-2]-48)+10*(s[i-1]-48)+(s[i]-48);
			d = abs(753-n);
			if(d<min) min = d;
		}
		printf("%d\n", min);
	}
	return 0;
}
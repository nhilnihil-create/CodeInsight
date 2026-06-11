#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int main(int argc, char const *argv[])
{
	int w;
	char s[1007];
	scanf("%s",s);
	scanf("%d",&w);
	for (int i = 0; i < strlen(s); i += w)	printf("%c", s[i]);
	puts("");
	return 0;
}

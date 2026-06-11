#include<stdio.h>
#include<string.h>
#include<math.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 63-A

int main(void)
{
	int w, i;
	char S[1000];
	scanf("%s", S);
	scanf("%d", &w);
	for (i = 0; i < strlen(S); i = i + w)
	{
		printf("%c", S[i]);
	}
	return 0;
}
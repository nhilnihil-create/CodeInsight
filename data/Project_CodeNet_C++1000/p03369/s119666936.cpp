#include <cstdio>

int main()
{
	char s[5];

	scanf("%s", s);

	int i;

	int count = 0;

	for (i = 0; i < 3; i++)
	{
		if (s[i] == 'o')
			count++;
	}

	printf("%d",700 + count * 100);
}
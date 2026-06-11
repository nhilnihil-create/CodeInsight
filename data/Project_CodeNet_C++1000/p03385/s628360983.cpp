#include <cstdio>

int main()
{
	char s[5];

	scanf("%s", s);
	
	int i;

	int counta = 0;
	int countb = 0;
	int	countc = 0;

	for (i = 0; i < 3; i++)
	{
		if (s[i] == 'a')
			counta++;
		if (s[i] == 'b')
			countb++;
		if (s[i] == 'c')
			countc++;
	}

	if (counta > 1 || countb > 1 || countc > 1)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
}
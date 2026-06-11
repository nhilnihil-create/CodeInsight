#include <cstdio>

int main()
{
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	if(b/a<=c)
	{
		printf("%d",(b/a));
	}
	else if(b/a>=c)
	{
		printf("%d", c);
	}
	else
	{
		printf("0");
	}
}
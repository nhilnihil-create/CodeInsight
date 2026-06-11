#include <stdio.h>
 
int main ()
{
	int a, b,jumlah=0;
	scanf("%d %d", &a, &b);
	char str[a+b+1];
	scanf("%s", str);
	for (int i=0;i<a+b+1;i++)
	{
		if(i!=a)
		{
			if(str[i]>='0' && str[i]<='9')
			{
				jumlah++;
			}
		}
			else if(str[i]=='-')
			{
				jumlah++;
			}
	}
		if(jumlah==a+b+1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	return 0;
}
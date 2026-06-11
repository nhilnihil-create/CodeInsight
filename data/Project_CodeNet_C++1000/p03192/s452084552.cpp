#include<cstdio>
char a;int t=0;
int main()
{
	while(scanf("%c",&a)!=EOF)
	{
		if(a=='2')
		{
			t++;
		}
	}
	printf("%d",t);
}
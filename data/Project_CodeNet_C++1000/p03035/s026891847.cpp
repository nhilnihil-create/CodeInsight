#include<cstdio>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<=5) b=0;
	if(a>=6&&a<=12) b/=2;
	printf("%d\n",b);
	return 0;
}

#include<cstdio>
int main()
{
	int a,p;
	scanf("%d %d",&a,&p);
	if(a>=1) a*=3;
	p=p+a;
	printf("%d\n",p/2);
	return 0;
}

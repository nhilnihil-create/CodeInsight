#include<cstdio>
int main()
{
	int a,b,c,i;
	scanf("%d %d %d",&a,&b,&c);
	for(i=0;i<10;i++){
		c=a*c-b;
		printf("%d\n",c);
	}
	return 0;
}

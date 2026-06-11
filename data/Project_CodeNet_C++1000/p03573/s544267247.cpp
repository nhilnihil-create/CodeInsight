#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a==b&&b==c) printf("%d\n",a);
	if(a==b&&a!=c) printf("%d\n",c);
	if(a!=b&&b==c) printf("%d\n",a);
	if(a==c&&b!=c) printf("%d\n",b);
}
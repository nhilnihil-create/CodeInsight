#include<stdio.h>
#include<algorithm>
#define min(a,b)(a<b?a:b)
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",min(b/a,c));
	return 0;
 } 
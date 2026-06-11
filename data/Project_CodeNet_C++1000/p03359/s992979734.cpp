#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b<a)
	{
		printf("%d\n",a-1);
	}
	else
	{
		printf("%d\n",a);
	}
	return 0;
} 
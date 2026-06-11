#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a%b)
		printf("%d",a);
	else
		printf("-1");
	return 0;
}
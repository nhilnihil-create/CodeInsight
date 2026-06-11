#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,h,w;
	scanf("%d %d %d",&n,&h,&w);
	printf("%d\n",(n-h+1)*(n-w+1));
	return 0;
}
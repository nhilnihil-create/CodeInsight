#include <iostream>
using namespace std;
int main()
{
	int n,mn=1e9;
	scanf("%d",&n);
	bool ok=0;
	long long s=0;
	while (n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ok|=(a!=b);
		s+=a;
		if (a>b)
		mn=min(mn,b);
	}
	if (!ok)
	printf("0");
	else
	printf("%lld",s-mn);
}
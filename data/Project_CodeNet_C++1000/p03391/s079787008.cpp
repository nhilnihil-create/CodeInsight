#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
ll n,a,b,sum,Min=INF;
bool flag=true;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		sum+=b;
		if(a!=b)
			flag=false;
		if(b<a&&Min>b)
			Min=b;
	}
	if(flag)
		printf("0\n");
	else
		printf("%lld\n",sum-Min);
	return 0;
}

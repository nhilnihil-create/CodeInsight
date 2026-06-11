#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
int a[100010];
int main()
{
	int i,j,k,n,m,x=0,y=inf;
	ll sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		x=x^(a[i]<0);
		y=min(y,abs(a[i]));
		sum+=abs(a[i]);
	}
	if(x)
	{
		sum-=2*y;
	}
	printf("%lld",sum);
	return 0;
}

// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=3e5+5;
int n,a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	LL mn=1e18,ok=1,sum=0;for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),sum+=a[i],ok&=(a[i]==b[i]),mn=min(mn,a[i]>b[i]?b[i]:(LL)1e9);
	if(ok)return puts("0"),0;printf("%lld\n",sum-mn);

	return 0;
}

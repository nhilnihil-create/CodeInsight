#include <bits/stdc++.h>
using namespace std;

//typedef __int128_t ll;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

const int maxN = 2e5 + 10;
const int maxC = 1e6 + 10;
const int INF1 = 1e9;
const ll INF = 1LL<<62;

ll a[maxN];
ll s[maxN];
ll Z;
int n;
int main()
{
	scanf("%d%lld",&n,&Z);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	s[0] = 0ll;
	for(int i=1;i<=n;i++)
	{
		s[i] = s[i-1] + a[i];
	}
	ll ans = INF;
	for(int k=1;k<=n;k++)
	{
		ll cur = 0ll;
		ll cof = 3ll;
		for(int i = n;i>=0;i-=k)
		{
			cur += (s[i] - s[max(0,i-k)]) * max(cof,5ll);
			cof += 2ll;
			if(cur > ans) break;
		}
		cur += (n+k)*Z;
		ans = min(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}
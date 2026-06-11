#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
constexpr int R=5e6+69, INF=2e9+6969;

int qq;
ll t[10][10], h,w,licz[10];

int main()
{
	ll n = 10;
	scanf("%lld%lld", &h, &w);
	for(ll i=0;i<n;++i) for(ll j=0;j<n;++j) scanf("%lld", &t[i][j]);
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<n;++j)
		{
			for(ll g=0;g<n;++g)
			{
				t[j][g]=min(t[j][g],t[j][i] + t[i][g]);
			}
		}
	}
	
	ll ans=0;
	for(ll i=0;i<h;++i)
	{
		for(ll j=0;j<w;++j)
		{
			ll x;
			scanf("%lld", &x);
			if(x==-1) continue;
			ans+=t[x][1];
		}
	}
	printf("%lld\n", ans);
	return 0;
}

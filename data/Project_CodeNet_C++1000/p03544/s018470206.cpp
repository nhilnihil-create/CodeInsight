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
constexpr int R=5e2+69, INF=2e9+6969;

int qq;

int main()
{
	ll n;
	ll t[R];
	cin >> n;
	t[0]=2;
	t[1]=1;
	for(int i=2;i<=n;++i) t[i]=t[i-1]+t[i-2];
	printf("%lld\n", t[n]);
	return 0;
}

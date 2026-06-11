#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
typedef pair<ll ,ll> pll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define sll(n) scanf("%lld",&n)
#define sll2(x,y) scanf("%lld%lld",&x,&y)
#define sll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define REP(i,x,y) for(ll i = x;i <= y;++i)
#define debug(x) cerr<<#x<<"::"<<x<<endl
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n"
#define debug4(x,y,z,w) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<"\n"
ll power(ll x,ll y,ll z) {
	ll ret = 1;
	while(y > 0) {
		if(y & 1) ret = (ret*x)%z;
		x = (x*x)%z;
		y >>= 1;
	}
	return ret;
}
const ll N = 17, inf = 1e15;
ll dp[1<<N], A[N][N], best[1<<N];
int main() {
	
	ll n;
	sll(n);
	REP(i,1,n) REP(j,1,n) sll(A[i][j]);
	ll mx = 1<<n;
	REP(mask,0,mx - 1) {
		vector<ll> idx;
		REP(i,0,n - 1) {
			if(mask & (1 << i)) idx.pb(i + 1);
		}
		ll sz = idx.size();
		for(ll i = 0;i < sz;++i) {
			ll x = idx[i];
			for(ll j = i;j < sz;++j) {
				ll y = idx[j];
				best[mask] += A[x][y];
			}
		}
	}
	REP(mask,0,mx - 1) {
		for(ll submask = mask;submask > 0;submask = (submask - 1)&mask) {
			dp[mask] = max(dp[mask], best[submask] + dp[mask^submask]);
		}
	}
	printf("%lld\n",dp[mx - 1]);

	

	return 0;
}
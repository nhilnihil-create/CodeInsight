#include<bits/stdc++.h>
using namespace std;
 
#define NL '\n'
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define ll long long
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define async() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 
//#define _debug 
void d(){cerr<<NL;}template<typename H,typename... T> void d(H h,T... t){cerr<<' '<<h;d(t... );}
#ifdef  _debug
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",d(__VA_ARGS__)
#else
#define debug(...) 
#endif

const ll N = 43;
ll n, k, x, l = 41, cnt[N], dp[N][2];

ll f(ll pos, bool status){
	ll cur = !!(k&(1LL<<(l-pos)));
	if(pos == l) {
		if(status) {
			if(cur == 1) return max(cnt[0], n - cnt[0]);
			return cnt[0];
		}
		return max(cnt[0], n - cnt[0]);
	}
	ll &ret = dp[pos][status];
	if(ret > -1LL) return ret;
	ll m = (1LL << (l-pos)), val = 0;
	if(status) {
		if(cur == 0) val = m*cnt[l-pos] + f(pos + 1, true);
		else val = max(m*cnt[l-pos]+f(pos+1, false), m*(n-cnt[l-pos])+f(pos+1, true));
	}
	else val = max(m*cnt[l-pos]+f(pos+1, false), m*(n-cnt[l-pos])+f(pos+1, false));
	return ret = val;
}

int main() {
	async();
	mem(dp, -1LL);
	cin >> n >> k; 
	rep(ix, 0, n) {cin >> x; for(ll i = N - 1; i >= 0;i--) if(x&(1LL<<i)) cnt[i]++;} 
	cout << f(0, true);
}    

#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	vector<ll> s(n+2), t(m+2);
	rep(i,n) cin >> s[i+1];
	rep(i,m) cin >> t[i+1];
	s[0] = t[0] = -INF;
	s[n+1] = t[m+1] = INF;
	rep(i,q){
		ll x;
		cin >> x;
		auto Rsh = lower_bound(s.begin(), s.end(), x);
		auto Rte = lower_bound(t.begin(), t.end(), x);
		auto Lsh = Rsh;
		auto Lte = Rte;
		--Lsh; --Lte;
		ll ans = INF;
		chmin(ans, x - min(*Lsh, *Lte));
		chmin(ans, max(*Rsh, *Rte) - x);
		chmin(ans, (*Rsh - *Lte) + min((*Rsh - x), (x - *Lte)));
		chmin(ans, (*Rte - *Lsh) + min((*Rte - x), (x - *Lsh)));
		cout << ans << endl;
	}
	return 0;
}
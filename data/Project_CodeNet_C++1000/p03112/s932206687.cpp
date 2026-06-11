#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e21;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a+2), t(b+2);
	rep(i,a) cin >> s[i];
	rep(i,b) cin >> t[i];
	s[a] = INF; s[a+1] = -INF;
	t[b] = INF; t[b+1] = -INF;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	ll x;
	rep(i,q){
		cin >> x;
		int s1, s2, t1, t2;
		s1 = lower_bound(s.begin(), s.end(), x) - s.begin();
		s2 = s1 - 1;
		t1 = lower_bound(t.begin(), t.end(), x) - t.begin();
		t2 = t1 - 1;
		ll ans = INF;
		if(s1 != 0 && t1 != 0 && s1 != a+1 && t1 != b+1) chmin(ans, max(s[s1],t[t1]) - x);
		if(s1 != 0 && t2 != 0 && s1 != a+1 && t2 != b+1) chmin(ans, 2*(s[s1]-x) + (x - t[t2]));
		if(s1 != 0 && t2 != 0 && s1 != a+1 && t2 != b+1) chmin(ans, 2*(x-t[t2]) + (s[s1] - x));
		if(s2 != 0 && t2 != 0 && s2 != a+1 && t2 != b+1) chmin(ans, x - min(s[s2],t[t2]));
		if(s2 != 0 && t1 != 0 && s2 != a+1 && t1 != b+1) chmin(ans, 2*(x-s[s2]) + (t[t1] - x));
		if(s2 != 0 && t1 != 0 && s2 != a+1 && t1 != b+1) chmin(ans, 2*(t[t1]-x) + (x - s[s2]));
		cout << ans << endl;
	}
	return 0;
}
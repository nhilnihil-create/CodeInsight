#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
	int n; cin >> n;
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	sort(all(a));
	vector<int> l(n);
	rep(i, n) cin >> l[i];

	// 4^nの全探索
	int ans = INF;
	rep(bit, pow(4, n)) {
		int tmp = bit;
		vector<int> s(4, 0);
		int cost = 0;
		rep(i, n) {
			if (tmp%4!=0 && s[tmp%4]!=0) cost += 10;
			s[tmp%4] += l[i];
			tmp/=4;
		}
		if (!s[1]||!s[2]||!s[3]) continue;
		rep(i, 3) {
			cost += abs(a[i]-s[i+1]);
		}
		chmin(ans, cost);
	}
	cout << ans << endl;
}
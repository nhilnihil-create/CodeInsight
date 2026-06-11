#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int N;
ll X[1000], Y[1000];

int main() {
	cin >> N;
	REP(i, N) scanf("%lld %lld", X + i, Y + i);
	
	bool par = X[0] + Y[0] & 1;
	
	vector<ll> cx(N), cy(N);
	REP(i, N) {
		if (par ^ X[i] + Y[i] & 1) {
			puts("-1");
			return 0;
		}
		if (!par) --X[i];
		cx[i] = X[i] - Y[i];
		cy[i] = X[i] + Y[i];
	}
	
	vector<ll> d;
	REP(i, 32) d.push_back(1ll<<i);
	ll S = accumulate(ALL(d), 0ll);
	
	vector<vector<bool> > fx(N, vector<bool>(d.size())), fy(N, vector<bool>(d.size()));
	REP(i, N) {
		ll x = cx[i] + S, y = cy[i] + S;
		FOR(j, 1, 33) {
			if (x >> j & 1) fx[i][j - 1] = 1;
			if (y >> j & 1) fy[i][j - 1] = 1;
		}
		
		if (!par) {
			fx[i].push_back(1);
			fy[i].push_back(1);
		}
	}
	if (!par) d.push_back(1);
	
	vector<string> ans;
	REP(i, N) {
		string cur;
		REP(j, d.size()) {
			string dat = "LUDR";
			cur += dat[fx[i][j] * 2 + fy[i][j]];
		}
		ans.push_back(cur);
	}
	
	cout << d.size() << endl;
	REP(i, d.size()) printf("%lld%c", d[i], i == d.size() - 1 ? '\n' : ' ');
	REP(i, N) cout << ans[i] << endl;
	
	if (debug) {
		if (!par) REP(i, N) ++X[i];
		REP(i, N) {
			ll x = 0, y = 0;
			REP(j, ans[i].size()) {
				switch (ans[i][j]) {
					case 'L': x -= d[j]; break;
					case 'R': x += d[j]; break;
					case 'U': y += d[j]; break;
					case 'D': y -= d[j]; break;
				}
			}
			printf("X:%lld x: %lld, Y:%lld, y:%lld\n", X[i], x, Y[i], y);
		}
	}
	
	return 0;
}

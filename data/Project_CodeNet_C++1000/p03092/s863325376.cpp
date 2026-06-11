#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
constexpr int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, a, b;
	cin >> n >> a >> b;
	vi v(n);
	REP(i, n) {
		cin >> v[i];
	}
	vvl dp(n + 1, vl(n+1, INF*INF));
	dp[0][0] = 0;
	REP(i, n) {
		ll m = *min_element(dp[i].begin(), dp[i].begin() + v[i]);
		dp[i + 1][v[i]] = m;
		REP(j, v[i])dp[i + 1][j] = dp[i][j] + a;
		FOR(j, v[i] + 1, n + 1) dp[i + 1][j] = dp[i][j] + b;
	}
	cout << *min_element(ALL(dp[n])) << endl;
}
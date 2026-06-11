#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///
string s;
int n;
int dfs(vi &dp, vi &pos, vi &bit, int i) {
	if (i == n)return 0;
	if (dp[i] != -1)return dp[i];
	//cout << i << endl;
	int ret = INF;
	int b = bit[n] ^ bit[i];
	int popcount = 0;

	b = bit[i];
	ret = min(ret, 1+pos[b]);

	REP(k, 26) {
		int c = b ^ (1 << k);
		ret = min(ret, 1+pos[c]);

	}
	//ret = min(ret, 1 + dfs(dp, pos, bit, i + 1));
	pos[b] = min(pos[b], ret);
	return dp[i] = ret;

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	n = s.size();
	vi bit(n + 1);

	vi pos(1 << 26, INF);
	bit[0] = 0;
	REP(i, n) {
		bit[i + 1] = bit[i] ^ (1 << (s[i] - 'a'));

	}
	pos[bit[n]] = 0;
	vi dp(n, -1);
	RREP(i, n)dfs(dp, pos, bit, i);
	cout << dp[0] << endl;
}

//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n-1;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m-1;i >= n;i--)
#define SORT(v, n) sort(v, v+n)
#define VSORT(v) sort(v.begin(), v.end())
#define REVERSE(v,n) reverse(v,v+n)
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define pb push_back
#define print(x) cout<<x<<'\n'
#define pe(x) cout<<x<<" "
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
//#define int long long
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7; const int MAX = 200060;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 1e18;

int pcnt(int x) {
	int cnt = 0;
	REP(i, 30) {
		if (x & (1 << i))cnt++;
	}
	return cnt;
}

int bit_dp[1 << 26];
int dp[200020];
int h[200020];
void solve() {
	string S; cin >> S;
	int N = S.size();
	REP(i, N) {
		int num = S[i] - 'a';
		h[i + 1] = h[i] ^ (1 << num);
	}
	REP(i, 1 << 26)bit_dp[i] = 1e9;
	REP(i, N) {
		int ret = 1e9;
		int num = S[i] - 'a';
		if (pcnt(h[i + 1]) <= 1)ret = 1;
		REP(x, 26) {
			int bit = (1 << x) ^ h[i + 1];
			ret = min(ret, bit_dp[bit]+1);
		}
		chmin(bit_dp[h[i + 1]], ret);
		dp[i + 1] = ret;
	}
	print(dp[N]);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();
}
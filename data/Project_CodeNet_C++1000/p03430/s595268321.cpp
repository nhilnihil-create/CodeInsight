#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
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
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9+7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;

string S; int K;

int dp[303][303][303];
int rec(int l, int r, int k) {
	if(dp[l][r][k])return dp[l][r][k];
	int res = 0;
	if (l == r)res = 1;
	else if (l + 1 == r) {
		if (S[l] == S[r] || k>0)res = 2;
		else res = 1;
	}
	else {
		chmax(res, rec(l + 1, r, k));
		chmax(res, rec(l, r - 1, k));
		if (S[l] == S[r])chmax(res, rec(l + 1, r - 1, k) + 2);
		else if (k > 0)chmax(res, rec(l + 1, r - 1, k - 1) + 2);
	}
	return dp[l][r][k] = res;
}

void solve() {
	cin >> S >> K;
	int N = S.size();
	print(rec(0, N-1, K));
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}


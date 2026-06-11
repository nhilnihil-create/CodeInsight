//#define _GLIBCXX_DEBUG
//#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define pb push_back 
#define f first
#define s second
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

template <class T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1e9;
//const ll INF = 1e18;
const ll mod = 1000000007;
// const ll mod = 998244353;

void solve(int tc){
	int n;
	cin >> n;
	vector<ld> p(n+1);
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	vector<vector<ld>> dp(n+1, vector<ld>(n+1, 0));

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		dp[0][i] = dp[0][i-1]*(1-p[i]);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = p[j]*dp[i-1][j-1] + (1-p[j])*dp[i][j-1];
	ld ans = 0;
	for(int i = n/2 + 1; i <= n; i++)
		ans += dp[i][n];

	cout << fixed << setprecision(10) << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	
	int tc = 1;
	//cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);

	return 0;
}
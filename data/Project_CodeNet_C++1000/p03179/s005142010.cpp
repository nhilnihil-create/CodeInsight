#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

int dp[3005][3005];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[1][i] = (dp[1][i] + dp[1][i - 1]) % mod;
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 1; j <= i + 2; j++) {
			if(s[i] == '>') {
				dp[i + 2][j] = (dp[i + 2][j] + dp[i + 1][i + 1] - dp[i + 1][j - 1] + mod) % mod;
			}
			else {
				dp[i + 2][j] = (dp[i + 2][j] + dp[i + 1][j - 1]) % mod;
			}
		}
		for(int j = 2; j <= i + 2; j++) {
			dp[i + 2][j] = (dp[i + 2][j] + dp[i + 2][j - 1]) % mod;
		}
	}
	cout << dp[n][n];

	return 0;
}
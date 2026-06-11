#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 
#define printVerdict(verdict) cout << (verdict ? "YES": "NO") << '\n'
#define printDecimal(d) printf("%.9f\n", d)
#define inrange(val, start, end) (val >= start && val <= end)
 
const int mod = 1e9 + 7; 
 
template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) { cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n'; }
template <class T1, class T2>
void printPair(pair<T1, T2> p) { cout << p.first << " " << p.second  << '\n'; }
template <class T>
void printArray(vector<T> arr) { for (int i = 0; i<size(arr); i++) {cout << arr[i] << " ";} cout << '\n'; }

ll evaluate(int curr, int mask, vector<vector<ll>> &dp, vector<vector<int>> &grid) {
	if (curr >= size(grid)) return 1;
	if (dp[curr][mask] != -1) return dp[curr][mask];
	ll ret = 0;
	for (int i =0; i<size(grid); i++) {
		if (!(mask&(1<<i)) && grid[curr][i]) {
			ret += evaluate(curr+1, mask|(1<<i), dp, grid);
			ret %= mod;
		}
	}
	dp[curr][mask] = ret;
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) cin >> grid[i][j];
	}
	vector<vector<ll>> dp(n, vector<ll>(1<<n, -1));
	ll ret = evaluate(0, 0, dp, grid);
	cout << ret << '\n';
}

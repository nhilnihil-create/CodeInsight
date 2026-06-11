#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int>dp(1 << 26, MOD);
	dp[0] = 0;
	int cbit = 0;
	int ans = MOD;
	for (auto i : s) {
		ans = MOD;
		int box = i - 'a';
		cbit ^= (1 << box);
		for (int j = 0; j < 26; j++) {
			ans = min(ans, dp[cbit ^ (1 << j)] + 1);
		}
		ans = min(ans, dp[cbit] + 1);
		dp[cbit] = min(dp[cbit], ans);
		//cout << " ";
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
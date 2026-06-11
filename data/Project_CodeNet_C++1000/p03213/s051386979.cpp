#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
int dp[101][76];
void solve() {
	int N; cin >> N;
	map<int, int> divide_prime;
	for (int i = 2; i <= N; ++i) {
		int n = i;
		for (int j = 2; j <= n; ++j) {
			while (n % j == 0) {
				divide_prime[j]++;
				n /= j;
			}
		}
	}
	vector<int> nums;
	for (auto z : divide_prime) nums.push_back(z.second);
	int lens = nums.size();
	vector<int> num_75 = {1, 3, 5, 15, 25, 75};
	dp[0][1] = 1;
	for (int i = 0; i < lens; ++i) {
		for (auto d1 : num_75) {
			for (auto d2 : num_75) {
				if (d1 * d2 <= 75 && nums[i]+1 >= d2) {
					dp[i + 1][d1 * d2] += dp[i][d1];
				}
			}
		}
	}
	cout << dp[lens][75] << endl;
	return;
}
int main() {
	solve();
	return 0;
}
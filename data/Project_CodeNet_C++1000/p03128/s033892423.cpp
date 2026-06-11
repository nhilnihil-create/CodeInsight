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

void solve() {
	int n, m; cin >> n >> m;
	vector<int> A(m);
	vector<int> num = {0,2,5,5,4,5,6,3,7,6};
	for (int i = 0; i < m; ++i) {
		cin >> A[i];
	}
	string dp[100001];
	for (int i = 1; i <= n; ++i) {
		dp[i] = "!";
	}
	dp[0] = "";
	for (int i = 2; i <= n; ++i) {
		for (int a: A) {
			if (i - num[a] < 0 || dp[i - num[a]] == "!") continue;
			string d2 = dp[i - num[a]];
			d2.push_back('0' + a);
			if (d2.size() > dp[i].size() || d2.size() == dp[i].size() && d2 > dp[i]) {
				dp[i] = d2;
			}
		}
	}
	cout << dp[n] << endl;
	return;
}
int main() {
	solve();
	return 0;
}
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a);i < (b);++i)
#define FORR(i, b, a) for (int i = (b) - 1;i >= 0;--i)
#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPR(i, n) for(int i = (n) - 1;i >= 0;--i)
#define ITER(itr, v) for(auto itr = v.begin();itr != v.end();++itr)
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SIZE(v) int(v.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	map<int, int> mp;
	for (int i = 2;i <= N;++i) {
		int n = i;
		for (int j = 2;j * j <= n;++j) {
			if (n % j) continue;
			while (n % j == 0) {
				mp[j]++;
				n /= j;
			}
		}
		if (n > 1) mp[n]++;
	}
	int n = SIZE(mp);
	vector<vector<int>> dp(n + 1, vector<int>(76));
	dp[0][1] = 1;
	int i = 0;
	for (auto &p : mp) {
		for (int j = 1;j <= 75;++j) {
			for (int k = 0;k <= p.second;++k) {
				if (j * (k + 1) > 75) break;
				dp[i + 1][j * (k + 1)] += dp[i][j];
			}
		}
		++i;
	}
	cout << dp[n][75] << endl;

	return 0;
}
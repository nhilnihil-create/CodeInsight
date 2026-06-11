#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<deque>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<string>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9 + 7);

string s, t;
vector<vector<int>> dp;

int main(void) {
	cin >> s >> t;
	if (s.size() < t.size())
		swap(s, t);
	dp = vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, 0));

	for (int i = 1; i < s.size() + 1; i++) {
		for (int j = 1; j < t.size() + 1; j++) {
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	int ret_size = dp[s.size()][t.size()];
	string ret(ret_size, ' ');
	int i = s.size();
	int j = t.size();
	while (ret_size > 0) {
		if (s[i - 1] == t[j - 1]) {
			ret[ret_size-1] = s[i - 1];
			i--;
			j--;
			ret_size--;
		}
		else if (dp[i - 1][j] == dp[i][j])
			i--;
		else
			j--;
	}
	cout << ret << endl;
	return 0;
}
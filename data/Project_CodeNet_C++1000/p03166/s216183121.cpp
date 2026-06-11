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

int n, m;
vector<vector<int>> node;
vector<int> dp;

int f(int i) {
	int ni_size = node[i].size();
	if (ni_size == 0) {
		dp[i] = 0;
		return 0;
	}
	else {
		if (dp[i] == -1) {
			int tmp = 0;
			for (int j = 0; j < ni_size; j++) {
				tmp = max(tmp, f(node[i][j]) + 1);
			}
			dp[i] = tmp;
			return tmp;
		}
		else
			return dp[i];
	}
}

int main(void) {
	cin >> n >> m;
	dp = vector<int>(n + 1, -1);
	node = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; i++) {
		int xi, yi;
		cin >> xi >> yi;
		node[xi].push_back(yi);
	}

	for (int i = 1; i < n + 1; i++)
		f(i);
	cout << *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}
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

constexpr char C = '.';
constexpr char W = '#';

int h, w;
vector<string> field;
vector<vector<ll>> dp;

void f(int i, int j) {
	if (i < h + 1 && j < w + 1 && field[i - 1][j - 1] == C) {
		dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
	}
}


int main(void) {
	cin >> h >> w;
	field = vector<string>(h);
	dp = vector<vector<ll>>(h + 1, vector<ll>(w + 1, 0));
	for (int i = 0; i < h; i++)
		cin >> field[i];
	dp[0][1] = 1;
	dp[1][0] = 0;
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			f(i, j);
		}
	}
	cout << dp[h][w] << endl;
	return 0;
}
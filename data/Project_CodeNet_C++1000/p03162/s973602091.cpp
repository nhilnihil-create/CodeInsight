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
constexpr int INF = 1 << 29;
constexpr ll MOD = ll(1e9 + 7);

constexpr int num = 3;

int n, cnt[num];		 //0:a, 1:b, 2:c
vector<vector<int>> abc, dp; //0:a, 1:b, 2:c

int maxh_without_j(int i, int j) {
	int hx = dp[(j + 1) % num][i - 1];
	int hy = dp[(j + 2) % num][i - 1];
	return max(hx, hy);
}



int main(void) {
	cin >> n;
	abc = vector<vector<int>>(num, vector<int>(n + 1, 0));
	dp = vector<vector<int>>(num, vector<int>(n + 1, 0));
	for (int i = 1; i < n + 1; i++)
		cin >> abc[0][i] >> abc[1][i] >> abc[2][i];

	dp[0][1] = abc[0][1];
	dp[1][1] = abc[1][1];
	dp[2][1] = abc[2][1];

	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < num; j++) {
			dp[j][i] = abc[j][i] +  maxh_without_j(i, j);
		}
	}
	cout << max({ dp[0][n], dp[1][n] , dp[2][n] }) << endl;
	return 0; {}
}
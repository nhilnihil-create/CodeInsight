#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

void In_Out() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
}
int m, n, p;
ll dp[1005][1005] = {0};

void display_grid(std::vector<vector<ll>> v) {
	for (auto ele : v) {
		for (auto item : ele) {
			cout << item << " ";
		}
		cout << endl;
	}
}

ll total_ways(int m, int n) {
	// if the starting block is blocked then no ways exist to reach dest.
	if (dp[0][0] == -1)
		return 0;
	// if the destination cell is blocked, there exists no way to reach it
	if (dp[m - 1][n - 1] == -1)
		return 0;
	// marking all the unblocked cells in the 0th row as 1 until we reach a cell which is blocked,
	// since after that blocked cell there would be no ways to reach any cells further in the 0th row
	for (int j = 0; j < n; j++) {
		if (dp[0][j] == -1)
			break;
		dp[0][j] = 1;
	}
	// similarly, for the 0th column
	for (int i = 0; i < m; i++) {
		if (dp[i][0] == -1)
			break;
		dp[i][0] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (dp[i][j] == -1)
				continue;
			if (dp[i][j - 1] != -1) {
				dp[i][j] = dp[i][j - 1] % MOD;
			}
			if (dp[i - 1][j] != -1) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			}

		}
	}
	return dp[m - 1][n - 1];
}

int main() {
	// In_Out();
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++){
            char ch;
            cin>>ch;
            if (ch == '#') dp[i][j] = -1;
        }
	}
	cout << total_ways(m, n) << endl;
}

// input -
// 4 3 2
// 3 3
// 3 1
// output -
// 2


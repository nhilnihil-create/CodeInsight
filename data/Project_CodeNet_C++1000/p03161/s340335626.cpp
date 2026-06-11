#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	long long inf = 1e18;

	int n, k;
	cin >> n >> k;

	vector<int> data(n + k + 10, inf);
	rep(i, n) {
		cin >> data[i];
	}

	vector<long long> dp(n + k + 10, inf);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k + 1; j++) {
			if (dp[i + j] > dp[i] + abs(data[i] - data[i + j]))  {
				dp[i + j] = dp[i] + abs(data[i] - data[i + j]);
			}
		}
	}
	//dp確認用
	/*
	rep(i, n) {
		cout << dp[i] << endl;
	}*/

	cout << dp[n - 1] << endl;
	return 0;
}
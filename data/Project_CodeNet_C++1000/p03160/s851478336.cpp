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

	int n;
	cin >> n;
	
	vector<int> data(n+1,inf);
	rep(i, n) {
		cin >> data[i];
	}

	vector<long long> dp(n+1, inf);
	dp[0] = 0;

	for (int i = 0; i < n - 1; i++) {
		if (abs(data[i] - data[i + 1]) + dp[i] < dp[i + 1]) {
			dp[i + 1] = abs(data[i] - data[i + 1])+dp[i];
		}
		if (abs(data[i] - data[i + 2] )+ dp[i] < dp[i + 2]) {
			dp[i + 2] = abs(data[i] - data[i + 2]) + dp[i];
		}
	}
	
	cout << dp[n-1] << endl;
	return 0;
}
#include<string>
#include<iostream>
#include<deque>
#include<cstdlib>
#include<algorithm>
using namespace std;
using lli = long long int;
using ulli = unsigned long long int;
#define rep(i, x, n) for(i=x;(i)<(n);(i)++)

const int MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	deque<lli> dp(n), nodes;
	int i;
	rep(i, 0, n) {
		lli temp;
		cin >> temp;
		nodes.push_back(temp);
	}
	rep(i, 0, n) {
		if (i == 0) {
			dp[i] = 0;
			continue;
		}
		else if (i == 1) {
			dp[i] = dp[i - 1] + abs(nodes[i] - nodes[i - 1]);
		}
		else {
			dp[i] = min(dp[i - 1] + abs(nodes[i] - nodes[i - 1]), dp[i - 2] + abs(nodes[i] - nodes[i - 2]));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
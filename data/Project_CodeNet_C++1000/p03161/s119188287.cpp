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
const int infty = 1000000000;

int main() {
	int n, k;
	cin >> n >> k;
	deque<lli> dp(n, infty), nodes;
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
		int j;
		rep(j, 1, min(k + 1, i + 1)) {
			dp[i] = min(dp[i], dp[i - j] + abs(nodes[i] - nodes[i - j]));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
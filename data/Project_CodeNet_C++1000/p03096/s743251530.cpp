#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)

const ll mod = 1000000007LL;

int main() {
	int n;
	cin >> n;
	int c[n];

	rep(i,n) {
		cin >> c[i];
	}

	int dp[n];
	dp[0] = 1;

	vector<int> prev(200001,-1);
	prev[c[0]] = 0; 

	for(int i = 1; i < n; i++) {
		int cur = dp[i - 1];

		if (prev[c[i]] >= 0 && i - 1 != prev[c[i]]) {
			cur += dp[prev[c[i]]];
		} 
		prev[c[i]] = i;

		dp[i] = cur % mod;
	}
	/*
	rep(i, n) {
		cout << "i:" << i << " n:" << dp[i] << endl;
	}
	*/

	cout << dp[n - 1] << endl;



	return 0;
}

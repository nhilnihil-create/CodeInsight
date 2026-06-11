#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> dp;

int rec(int n) {

	int res = n;
	if (n == 0) return 0;
	if (dp[n] != -1) return dp[n];
	
	for (int p = 1; p <= n; p *= 6) res = min(res, rec(n - p) + 1);
	for (int p = 1; p <= n; p *= 9) res = min(res, rec(n - p) + 1);

	return dp[n] = res;
}

int main() {

	int n; cin >> n;

	dp.resize(n+1,-1);

	int res = rec(n);

	cout << res << endl;

}
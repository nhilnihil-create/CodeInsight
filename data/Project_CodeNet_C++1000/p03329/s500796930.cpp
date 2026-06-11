#include <bits/stdc++.h>
#define INF 1001001001
using namespace std;
const int MAXN = 100010;
int main() {
	int n;
	cin >> n;
	vector<int> dp(100100, INF);
	dp[0] = 0;
	vector<int> p;
	int a = 1;
	while (a < MAXN) {
		p.push_back(a);
		a *= 9;
	}
	a = 1;
	while (a < MAXN) {
		p.push_back(a);
		a *= 6;
	}
	for (int i = 0; i < MAXN; i++) {
		for (int m : p) {
			if (i + m > MAXN)
				continue;
			dp[i + m] = min(dp[i + m], dp[i] + 1);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
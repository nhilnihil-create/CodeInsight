#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[300500];
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + (s[i] == 'W');
	}
	int res = INT_MAX;
	for (int i = 1; i <= n; i++) {
		res = min(res, pre[i - 1] + n - i - pre[n] + pre[i]);
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}
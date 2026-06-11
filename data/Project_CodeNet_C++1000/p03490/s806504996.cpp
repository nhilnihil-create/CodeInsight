#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8005;

vector<int> arr;
int dp[MAXN][2*MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;
	arr.push_back(0);
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == 'T') arr.push_back(0);
		else arr.back()++;
	}
	int N = arr.size();

	int x, y;
	cin >> x >> y;


	if (arr.size() == 1) {
		if (x == arr[0]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		return 0;
	}

	x -= arr[0];
	x += MAXN; y += MAXN;
	dp[0][MAXN] = dp[1][MAXN+arr[1]] = dp[1][MAXN-arr[1]] = 1;
	for (int pos = 2; pos < N; pos++) {
		for (int rem = 0; rem < 2*MAXN; rem++) {
			int &ret = dp[pos][rem];
			ret = 0;
			if (rem + arr[pos] < 2*MAXN) ret |= dp[pos-2][rem+arr[pos]];
			if (rem - arr[pos] >= 0) ret |= dp[pos-2][rem-arr[pos]];
		}
	}
	if (N&1) {
		if (dp[N-1][x] && dp[N-2][y]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	} else {
		if (dp[N-1][y] && dp[N-2][x]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}
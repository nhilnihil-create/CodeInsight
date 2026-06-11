#include "bits/stdc++.h"
using namespace std;
bool dp[2][16001];
int main() {
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	vector<int> X, Y;
	int pos = 0;
	while (pos < s.size() && s[pos] == 'F') pos++, x--;
	bool moveX = 1;
	int d = 0;
	while (pos < s.size()) {
		if (s[pos] == 'F') {
			d++;
		}
		else {
			if (moveX) X.push_back(d);
			else Y.push_back(d);
			moveX ^= 1;
			d = 0;
		}
		pos++;
	}
	if (moveX) X.push_back(d);
	else Y.push_back(d);
	dp[0][s.size()] = 1;
	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j <= 2 * s.size(); j++) {
			if (!dp[i & 1][j]) continue;
			if (j + X[i] <= 2 * s.size()) dp[(i + 1) & 1][j + X[i]] = 1;
			if (0 <= j - X[i]) dp[(i + 1) & 1][j - X[i]] = 1;
			dp[i & 1][j] = 0;
		}
	}
	if (!dp[X.size() & 1][x + s.size()]) {
		cout << "No" << endl;
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][s.size()] = 1;
	for (int i = 0; i < Y.size(); i++) {
		for (int j = 0; j <= 2 * s.size(); j++) {
			if (!dp[i & 1][j]) continue;
			if (j + Y[i] <= 2 * s.size()) dp[(i + 1) & 1][j + Y[i]] = 1;
			if (0 <= j - Y[i]) dp[(i + 1) & 1][j - Y[i]] = 1;
			dp[i & 1][j] = 0;
		}
	}
	if (!dp[Y.size() & 1][y + s.size()]) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

string str;
int x, y, xx, yy;
vector<int> v[2];
int dp[4001][16001];

int func(int i, int idx, int val, int goal) {
	if (idx == v[i].size() && val == goal) return 1;
	else if (idx == v[i].size()) return 0;

	int& ret = dp[idx][val + 8000];
	if (ret != -1) return ret;
	ret = 0;
	ret += func(i, idx + 1, val + v[i][idx], goal);
	if (ret) return ret;
	ret += func(i, idx + 1, val - v[i][idx], goal);
	return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	cin >> xx >> yy;
	bool start = 0;
	int dir = 0, cnt = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (start == 1 && (str[i] == 'T' || i == str.length()-1)) {
			if (str[i] == 'F') cnt++;
			v[dir % 2].push_back(cnt);
			dir++; cnt = 0;
		}
		else if (start) cnt++;

		if (start == 0 && str[i] == 'F') x++;
		else if (start == 0 && str[i] == 'T') start = 1, cnt = 0;
	}

	xx = abs(x - xx);
	yy = abs(y - yy);

	memset(dp, -1, sizeof(dp));
	if (func(1, 0, 0, xx)) {
		memset(dp, -1, sizeof(dp));
		if (func(0, 0, 0, yy)) {
			cout << "Yes";
		}
		else cout << "No";
	}
	else {
		cout << "No";
	}
	return 0;
}
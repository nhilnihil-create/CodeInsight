#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, C;
	cin >> N >> C;

	vector<vector<bool>> channel(C, vector<bool>(100000));
	for (int i = 0; i < N; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		for (int j = s - 1; j < t; j++) channel.at(c - 1).at(j) = 1;
	}

	int ans = 0;
	for (int i = 0; i < 100000; i++) {
		int cnt = 0;

		for (int j = 0; j < C; j++) {
			if (channel.at(j).at(i)) cnt++;
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;
}
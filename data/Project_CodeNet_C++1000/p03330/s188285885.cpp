#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, C;
	cin >> N >> C;

	vector<vector<int>> D(C, vector<int>(C)), c(N, vector<int>(N));
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			cin >> D.at(i).at(j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c.at(i).at(j);
			c.at(i).at(j)--;
		}
	}

	vector<vector<int>> cost(3, vector<int>(C));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < C; k++) {
				cost.at((i + j) % 3).at(k) += D.at(c.at(i).at(j)).at(k);
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			if (i == j) continue;
			for (int k = 0; k < C; k++) {
				if (k == i) continue;
				if (k == j) continue;
				ans = min(ans, cost.at(0).at(i) + cost.at(1).at(j) + cost.at(2).at(k));
			}
		}
	}

	cout << ans << endl;
}
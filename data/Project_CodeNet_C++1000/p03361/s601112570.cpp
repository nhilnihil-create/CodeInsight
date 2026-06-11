#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector<vector<char>> c(52, vector<char>(52));
int H, W, cnt;
int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (c[i][j] == '#' && c[i][j - 1] != '#' && c[i - 1][j] != '#' && c[i][j + 1] != '#' && c[i + 1][j] != '#') cnt++;
		}
	}
	if (cnt == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

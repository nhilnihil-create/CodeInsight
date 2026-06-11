#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7;

int H, W, perms[1005][1005];
string grid[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> H >> W;
	for (int i=1;i<=H;++i) cin >> grid[i];
	perms[1][1] = 1;
	for (int i=1;i<=H;++i) {
		grid[i] = "!"+grid[i];
		for (int j=1;j<=W;++j) {
			if (grid[i][j] == '.') {
				if (grid[i-1][j] == '.') perms[i][j] = (perms[i][j]+perms[i-1][j])%M;
				if (grid[i][j-1] == '.') perms[i][j] = (perms[i][j]+perms[i][j-1])%M;
			}
		}
	}
	cout << perms[H][W] << '\n';
	return 0;
}
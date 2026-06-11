#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
const int N = 300;

int n;
char grid[N][2 * N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
		for (int j = 0; j < n; ++j) grid[i][j + n] = grid[i][j];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		bool valid = true;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (grid[j][k + i] != grid[k][j + i]) valid = false;
			}
		}
		
		if (valid) ++ans;
	}
	
	cout << ans * n;
}

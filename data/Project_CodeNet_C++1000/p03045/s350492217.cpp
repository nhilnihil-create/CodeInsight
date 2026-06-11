#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<int> b;

void dfs(int n, int p);

int main()
{
	int n, m;
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		a[x].emplace_back(y);
		a[y].emplace_back(x);
		b[x] = 1;
		b[y] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) {
			ans++;
			dfs(i, i);
		} else if (b[i] == 0) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}

void dfs(int n, int p)
{
	if (b[n] == 2) {
		return;
	}
	b[n] = 2;

	for (auto & i : a[n]) {
		if (i == p) continue;

		dfs(i, n);
	}
}
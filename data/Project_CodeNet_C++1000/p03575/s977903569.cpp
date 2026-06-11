#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(50);

bool dfs(vector<int> u, int n, int p, int s);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<int> u(n);
		if (dfs(u, i, i, i)) {
			ans++;
		}
	}

	cout << (ans == n ? ans - 1 : ans) << endl;

	return 0;
}

bool dfs(vector<int> u, int n, int p, int s)
{
	if (n != p && n == s) {
		return false;
	}

	if (u[n] != 0) {
		return true;
	}
	u[n] = 1;

	for (auto & i : v[n]) {
		if (i == p) {
			continue;
		}

		if (!dfs(u, i, n, s)) {
			return false;
		}
	}
	return true;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t = 0;
vector<vector<int>> a(10010);
vector<int> d(10010);
vector<int> ans(10010);

void dfs(int n, int p)
{
	ans[n] = d[t];
	t++;
	for (auto& i : a[n]) {
		if (i == p) continue;
		dfs(i, n);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int b, c;
		cin >> b >> c;
		b--;
		c--;
		a[b].emplace_back(c);
		a[c].emplace_back(b);
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		sum += d[i];
	}
	sort(d.rbegin(), d.rend());
	sum -= d[0];
	dfs(0, 0);

	cout << sum << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
	}

	return 0;
}
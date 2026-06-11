#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, a, b, s, id, pp;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<long long> c(n);
	vector<long long> ans(n + 1);
	for (i = 0; i < n; i++) cin >> c[i];

	sort(c.rbegin(), c.rend());
	queue<int> q;
	q.push(1);
	vector<bool> used(n + 1, false);
	used[1] = true;
	pp = 0;

	while (!q.empty()) {
		id = q.front();
		q.pop();
		ans[id] = c[pp++];

		for (auto p : adj[id]) {
			if (!used[p]) {
				used[p] = true;
				q.push(p);
			}
		}
	}

	s = 0;
	for (i = 1; i < n; i++) s += c[i];

	cout << s << "\n";
	for (i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << "\n";

	return 0;
}


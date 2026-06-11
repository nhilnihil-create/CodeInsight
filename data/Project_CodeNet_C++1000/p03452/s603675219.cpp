#include <bits/stdc++.h>

struct edge
{
	int to;
	long long cost;
};

int n, m;
std::vector<edge> e[100005];
long long v[100005];
bool visited[100005];

int main()
{
	std::cin >> n >> m;

	int start;
	for (int i = 0; i < m; ++i) {
		int l, r, d;
		std::cin >> l >> r >> d;
		--l, --r;
		if (i == 0)
			start = l;

		edge tmp;
		tmp.to = r, tmp.cost = d;
		e[l].emplace_back(tmp);
		tmp.to = l, tmp.cost = -d;
		e[r].emplace_back(tmp);
	}

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = 1;
			v[i] = 0;
			std::queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int val = q.front(); q.pop();
				for (int p = 0; p < e[val].size(); ++p) {
					if (visited[e[val][p].to]) {
						if (v[val] + e[val][p].cost != v[e[val][p].to]) {
							std::cout << "No" << std::endl;
							return 0;
						}
					}
					else {
						v[e[val][p].to] = v[val] + e[val][p].cost;
						visited[e[val][p].to] = 1;
						q.push(e[val][p].to);
					}
				}
			}
		}
	}

	std::cout << "Yes" << std::endl;
	return 0;
}

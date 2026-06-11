#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

struct UnionFind {
        int n;
        vector<int> parent;
        vector<int> rank;
        vector<int> num;
        int find(int x) {
                if (parent[x] == x) return  x;
                return parent[x] = find(parent[x]);
        }
        UnionFind(int n_) {
                n = n_;
                parent.resize(n);
                for (int i = 0; i < n; i ++) parent[i] = i;
                rank.assign(n, 0);
                num.assign(n, 1);
        }
        void unite(int x, int y) {
                if ((x = find(x)) != (y = find(y))) {
                        if (rank[x] < rank[y]) {
                                parent[x] = y;
                                num[y] += num[x];
                        } else {
                                parent[y] = x;
                                if (rank[x] == rank[y]) rank[x] ++;
                                num[x] += num[y];
                        }
                        n --;
                }
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int get() { return n; }
        int get(int x) { return num[find(x)]; }
};

int main() {
	auto no = [](){ puts("-1"); exit(0); };
	int n;
	scanf("%d", &n);
	vector<long long> d(n);
	map<long long, int> mp;
	set<long long> ds;
	rep(i, n) {
		scanf("%lld", &d[i]);
		ds.insert(d[i]);
		mp[d[i]] = i;
	}
	sort(d.rbegin(), d.rend());
	UnionFind uf(n);
	vector<pair<int, int>> ans;
	rep(i, n - 1) {
		long long cur = d[i];
		int sz = uf.get(mp[cur]);
		int d = n - 2 * sz;
		long long par = cur - d;
		if (ds.count(par) == 0) {
			no();
		}
		ans.emplace_back(mp[cur], mp[par]);
		uf.unite(mp[cur], mp[par]);
	}
	vector<vector<int>> g(n);
	rep(i, n - 1) {
		int a = ans[i].first;
		int b = ans[i].second;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<long long> s(n);
	vector<int> dis(n);
	vector<int> sz(n);
	function<void (int, int)> dfs = [&](int u, int prev) {
		sz[u] = 1;
		for (auto v : g[u]) if (v != prev) {
			dis[v] = dis[u] + 1;
			dfs(v, u);
			sz[u] += sz[v];
		}
	};
	dfs(0, -1);
	rep(i, n) s[0] += dis[i];
	function<void (int, int)> dfs2 = [&](int u, int prev) {
		for (auto v : g[u]) if (v != prev) {
			s[v] = s[u] + n - sz[v] * 2;
			dfs2(v, u);
		}
	};
	dfs2(0, -1);
	sort(s.begin(), s.end());
	sort(d.begin(), d.end());
	if (s != d) {
		cout << -1 << endl;
		return 0;
	}
	for (auto it : ans) printf("%d %d\n", it.first + 1, it.second + 1);
        return 0;
}

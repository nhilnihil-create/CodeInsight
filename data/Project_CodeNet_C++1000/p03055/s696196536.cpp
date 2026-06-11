#include <bits/stdc++.h>

#define fori(i, a, b) for (int i = a; i < b; ++ i)
#define fori2(i, a, b) for (int i = a; i <= b; ++ i)
#define ford(i, a, b) for (int i = a; i >= b; -- i)

using namespace std;

typedef long long ll;

const int N = 2e5;

int n;

vector <int> adj[N];

pair <int, int> visit(int u, int u2) {
		pair <int, int> ans;

		ans.first = 0;
        ans.second = u;

		pair <int, int> a;

		for (int v: adj[u]) {
                if (v == u2)
                        continue;

                a = visit(v, u);
                if (a.first + 1 > ans.first) {
                        ans.first = a.first + 1;
                        ans.second = a.second;
                }
		}

		return(ans);
}

void process() {
		cin >> n;

		fori(i, 0, n - 1) {
				int u, v;

				cin >> u >> v;

				-- u;
				-- v;

				adj[u].push_back(v);
				adj[v].push_back(u);
		}

		int ans, v;

		v = visit(0, -1).second;

		ans = visit(v, -1).first;

		if (ans % 3 == 1) {
				cout << "Second";
				return;
		} else {
				cout << "First";
				return;
		}
}

int main() {
        ios::sync_with_stdio(false);
        process();
}


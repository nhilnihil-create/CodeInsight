#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = INT_MAX;
constexpr ll L_INF = LLONG_MAX;

//===


using Graph = std::vector<std::vector<int>>;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	Graph g(N);
	Vi indeg(N);
	for (int i = 0; i < N - 1 + M; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		++indeg[b];
	}

	Vi ans(N);

	stack<int> st;
	for (int i = 0; i < N; ++i) {
		if (indeg[i] == 0) {
			st.push(i);
			ans[i] = 0;
			break;
		}
	}

	while (!st.empty()) {
		int u = st.top();
		st.pop();
		for (const auto& to : g[u]) {
			--indeg[to];
			if (indeg[to] == 0) {
				ans[to] = u + 1;
				st.push(to);
			}
		}
	}

	for (const auto& ansi : ans) {
		cout << ansi << "\n";
	}


	return 0;
}
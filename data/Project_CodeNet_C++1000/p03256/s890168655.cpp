#include <bits/stdc++.h>

using namespace std;

template <typename T>
using V = vector<T>;

typedef long double ld;
typedef long long ll;

#define FO(i, N) for (int (i) = 0; (i) < (N); ++(i))
#define FOll(i, N) for (ll (i) = 0; (i) < (N); ++(i))
#define READALL(c) for (auto &e : c) { cin >> e; }
#define PRINTALL(c) for (const auto &e : c) { cout << e << "\t"; } cout << "\n";
#define MP(x, y) (make_pair((x), (y)))
#define MT(...) make_tuple(__VA_ARGS__)
#define G(i, x) get<i>(x)
#define ALL(x) begin(x), end(x)

const int MAXN = 2*1e5+10;
int N, M;
set<int> adj_A[MAXN], adj_B[MAXN];
string S;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> S;
	FO(i, M) {
		int u,v;
		cin >> u >> v;
		--u; --v;
		if (S[v] == 'A') adj_A[u].insert(v);
		else adj_B[u].insert(v);
		if (S[u] == 'A') adj_A[v].insert(u);
		else adj_B[v].insert(u);
	}
	queue<int> Q;
	V<int> marked(N);
	FO(i, N) if (adj_A[i].empty() || adj_B[i].empty()) {
		Q.push(i);
		marked[i] = 1;
	}
	while (Q.size()) {
		int curr = Q.front();
		Q.pop();
		for (int c : adj_A[curr]) if (!marked[c]) {
			auto& cadj = (S[curr] == 'A' ? adj_A[c] : adj_B[c]);
			cadj.erase(curr);
			if (cadj.empty()) {
				Q.push(c);
				marked[c] = 1;
			}
		}
		for (int c : adj_B[curr]) if (!marked[c]) {
			auto& cadj = (S[curr] == 'A' ? adj_A[c] : adj_B[c]);
			cadj.erase(curr);
			if (cadj.empty()) {
				Q.push(c);
				marked[c] = 1;
			}
		}
	}
	cout << (accumulate(ALL(marked), 0) == N ? "No" : "Yes") << endl;
}
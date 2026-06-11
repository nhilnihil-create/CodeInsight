#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		vector<vector<UL>> E(N);
		vector<UL> F(N);
		vector<UL> P(N, -1);
		rep(i, N + M - 1) {
			UL u, v; cin >> u >> v; u--; v--;
			E[u].push_back(v);
			F[v]++;
		}
		queue<UL> Q; rep(i, N) if (F[i] == 0) Q.push(i);
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			for (UL e : E[p]) {
				F[e]--;
				if (F[e] == 0) {
					P[e] = p;
					Q.push(e);
				}
			}
		}
		rep(i, N) cout << (P[i] + 1) << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
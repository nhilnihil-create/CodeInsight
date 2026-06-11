#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		string S; cin >> S;
		vector<vector<UL>> E(N * 2);
		rep(i, M) {
			UL a, b; cin >> a >> b; a--; b--;
			if (S[a] == S[b]) {
				E[2 * a].push_back(2 * b + 1);
				E[2 * b].push_back(2 * a + 1);
			}
			else {
				E[2 * a + 1].push_back(2 * b);
				E[2 * b + 1].push_back(2 * a);
			}
		}
		vector<UL> F(N * 2);
		rep(i, E.size()) for (UL e : E[i]) F[e]++;
		queue<UL> Q; rep(i, N * 2) if (F[i] == 0) Q.push(i);
		vector<UL> tol;
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			tol.push_back(p);
			for (UL e : E[p]) { F[e]--; if (F[e] == 0) Q.push(e); }
		}
		if (tol.size() == 2 * N) cout << "No" << endl;
		else cout << "Yes" << endl;
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
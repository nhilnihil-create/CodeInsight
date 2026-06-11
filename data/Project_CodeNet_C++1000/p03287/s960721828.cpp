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
		vector<UL> F(N + 1);
		rep(i, N) {
			UL f; cin >> f;
			F[i + 1] = F[i] + f;
			F[i + 1] %= M;
		}
		map<UL, UL> Q;
		ULL ans = 0;
		rep(i, N + 1) {
			auto p = Q.find(F[i]);
			if (p == Q.end()) Q[F[i]] = 1;
			else {
				ans += p->second;
				Q[F[i]]++;
			}
		}
		cout << ans << endl;
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

#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> P(N); rep(i, N) { cin >> P[i]; P[i]--; }
		vector<UL> p(N);
		UL ans = 0;
		rep(i, N) {
			p[P[i]] = 1;
			if (P[i]) p[P[i]] += p[P[i] - 1];
			ans = max(ans, p[P[i]]);
		}
		cout << (N - ans) << endl;
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
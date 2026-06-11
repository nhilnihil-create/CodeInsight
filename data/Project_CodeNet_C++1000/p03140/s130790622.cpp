#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		string A, B, C; cin >> A >> B >> C;
		UL ans = 0;
		rep(i, N) {
			if (A[i] == B[i] && B[i] == C[i]) continue;
			else if (A[i] == B[i]) ans++;
			else if (B[i] == C[i])ans++;
			else if (C[i] == A[i]) ans++;
			else ans += 2;
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
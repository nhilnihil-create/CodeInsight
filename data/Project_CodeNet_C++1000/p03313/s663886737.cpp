#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve2(UL *A, UL *ans, UL N) {
		if (N == 1) {
			ans[0] = 0; ans[1] = A[0] + A[1];
			//cout << "A={" << A[0] << "," << A[1] << "},ans={" << ans[0] << " " << ans[1] << "}" << endl;
			return;
		}
		UL S = (1u << (N - 1));
		UL *A1 = A + S, *ans1 = ans + S;
		vector<UL> Abuf(S * 2); rep(i, S * 2) Abuf[i] = A[i];
		vector<UL> Ap(S); rep(i, S) { Ap[i] = A[i] + A1[i]; }
		rep(i, S) { A1[i] = max(A[i], A1[i]); }
		Solve2(A, ans, N - 1);
		Solve2(A1, ans1, N - 1);
		rep(i, S) { ans1[i] = max(ans1[i], Ap[i]); }
		rep(i, S * 2 - 1) ans[i + 1] = max(ans[i + 1], ans[i]);
		//cout << "A={"; rep(i, Abuf.size()) { if (i)cout << ","; cout << Abuf[i]; }
		//cout << "},ans={"; rep(i, S * 2) { if (i)cout << ","; cout << ans[i]; }
		//cout << "}" << endl;
	}

	void Solve() {
		UL N; cin >> N;
		UL S = 1u << N;
		vector<UL> A(S); rep(i, S) cin >> A[i];
		vector<UL> ans(S);
		Solve2(&A[0], &ans[0], N);
		for (UL i = 1; i < S; i++) cout << ans[i] << endl;
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

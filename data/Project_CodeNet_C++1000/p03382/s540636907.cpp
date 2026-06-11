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
		vector<UL> A(N); rep(i, N) cin >> A[i];
		sort(A.begin(), A.end());
		UL Ai = A[N - 1];
		UL Aj = A[0];
		rep(i, N - 1) {
			UL dj = max(Aj * 2, Ai) - min(Aj * 2, Ai);
			UL d = max(A[i] * 2, Ai) - min(A[i] * 2, Ai);
			if (dj > d) Aj = A[i];
		}
		cout << Ai << " " << Aj << endl;
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

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
		if (A[0]) { cout << -1 << endl; return; }
		ULL ans = 0;
		for (UL i = 1; i < N; i++) {
			if (A[i] > A[i - 1] + 1) { cout << -1 << endl; return; }
			if (A[i] == A[i - 1] + 1) { ans++; continue; }
			else { ans += A[i]; }
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
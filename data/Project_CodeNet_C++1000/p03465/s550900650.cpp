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
		bitset<2000010> B;
		B.set(0);
		UL S = 0;
		rep(i, N) {
			B |= (B << A[i]);
			S += A[i];
		}
		for (UL i = (S + 1) / 2; i <= S; i++) {
			if (B[i]) { cout << i << endl; return; }
		}
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
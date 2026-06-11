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
		vector<UL> B(N); rep(i, N) cin >> B[i];
		UL ans = 0;
		for (int d = 28; d >= 0; d--) {
			UL D = 1 << d;
			ULL C = 0;
			rep(i, N) {
				if (A[i] & D) { C += N; A[i] ^= D; }
				if (B[i] & D) { C += N; B[i] ^= D; }
			}
			sort(A.begin(), A.end());
			rep(i, N) {
				UL p = B[i];
				p = D - p;
				UL l = 0, r = N + 1;
				while (l + 1 < r) {
					UL m = (l + r) >> 1;
					if (A[m - 1] < p) l = m; else r = m;
				}
				C += N - l;
			}
			if (C & 1) ans |= D;
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

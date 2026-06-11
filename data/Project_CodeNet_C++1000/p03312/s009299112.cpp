#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	ULL f(ULL a,ULL b,ULL c,ULL d){
		return max(max(a, b), max(c, d)) -
			min(min(a, b), min(c, d));
	}

	void Solve() {
		UL N; cin >> N;
		vector<ULL> A(N); rep(i, N) cin >> A[i];
		rep(i, N - 1) A[i + 1] += A[i];
		ULL ans = 1e18;
		for (UL d = 1; d < N - 2; d++) {
			ULL M1 = A[d], M2 = A[d] + A[N - 1];
			UL l1 = 0, r1 = d;
			while (l1 < r1 - 1) {
				UL m = (l1 + r1) / 2;
				if (A[m] * 2 <= M1) l1 = m; else r1 = m;
			}
			UL l2 = d + 1, r2 = N - 1;
			while (l2 < r2 - 1) {
				UL m = (l2 + r2) / 2;
				if (A[m] * 2 <= M2) l2 = m; else r2 = m;
			}
			ans = min(ans, f(A[l1], A[d] - A[l1], A[l2] - A[d], A[N - 1] - A[l2]));
			if (r1 != d) ans = min(ans, f(A[r1], A[d] - A[r1], A[l2] - A[d], A[N - 1] - A[l2]));
			if (r2 != N - 1) ans = min(ans, f(A[l1], A[d] - A[l1], A[r2] - A[d], A[N - 1] - A[r2]));
			if (r1 != d && r2 != N - 1) ans = min(ans, f(A[r1], A[d] - A[r1], A[r2] - A[d], A[N - 1] - A[r2]));
			//cout << d << " : " << l1 << " " << l2 << endl;
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

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
		vector<ULL> A(N), B(N); rep(i, N) cin >> A[i] >> B[i];
		vector<ULL> C(N); rep(i, N) C[i] = A[i] + B[i];
		sort(C.rbegin(), C.rend());
		LL ans = 0;
		rep(i, N) ans -= B[i];
		rep(i, N) if (i % 2 == 0) ans += C[i];
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
#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	static ULL gcd(ULL a, ULL b) { return b ? gcd(b, a % b) : a; }
	static const ULL M = 1000000007;

	void Solve() {
		UL N; cin >> N;
		vector<ULL> A(N); rep(i, N) cin >> A[i];
		vector<ULL> iF(N + 1); iF[N] = 1;
		for (UL i = N; i > 0; i--) iF[i - 1] = iF[i] * i % M;
		vector<ULL> F(N + 1); F[0] = 1; rep(i, N) F[i + 1] = F[i] * (i + 1) % M;
		for (UL i = 1; i <= N; i++) iF[i] = iF[i] * F[i - 1] % M;
		ULL ans = 0;
		rep(i, N) ans += A[i] * iF[1] % M;
		ans %= M;
		vector<ULL> SF(N + 1); SF[1] = 0;
		for (UL i = 2; i <= N; i++) SF[i] = (SF[i - 1] + iF[i]) % M;
		//rep(i, N) cout << SF[i + 1] << " "; cout << endl;
		for (UL i = 0; i < N; i++) {
			UL l = i + 1, r = N - i;
			ans += (SF[l] + SF[r]) * A[i] % M;
		}
		ans %= M;
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
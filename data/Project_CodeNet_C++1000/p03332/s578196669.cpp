#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	static const ULL M = 998244353;

	void Solve(){
		ULL N, A, B, K; cin >> N >> A >> B >> K;

		vector<ULL> C(N + 1);
		{
			vector<ULL> I(N + 1); I[1] = 1;
			for (UL i = 2; i <= N; i++) I[i] = M - M / i * I[M % i] % M;
			vector<ULL> iF(N + 1); iF[0] = 1;
			for (UL i = 1; i <= N; i++) iF[i] = iF[i - 1] * I[i] % M;
			vector<ULL> F(N + 1); F[0] = 1;
			for (UL i = 1; i <= N; i++) F[i] = F[i - 1] * i % M;
			rep(i, N + 1) C[i] = F[N] * iF[i] % M * iF[N - i] % M;
		}

		ULL ans = 0;
		rep(i, N + 1) {
			ULL AA = A * i;
			if (AA > K) continue;
			if ((K - AA) % B != 0) continue;
			ULL j = (K - AA) / B;
			if (j > N) continue;
			ans += C[i] * C[j] % M;
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
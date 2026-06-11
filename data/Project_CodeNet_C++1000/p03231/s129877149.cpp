#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	static ULL gcd(ULL a, ULL b) { return b ? gcd(b, a % b) : a; }

	void Solve() {
		ULL N, M; cin >> N >> M;
		ULL G = gcd(N, M);
		ULL ans = N * M / G;
		string S, T; cin >> S >> T;
		{
			UL n = N / G, m = M / G;
			rep(i, G) {
				if (S[n * i] != T[m * i]) { cout << -1 << endl; return; }
			}
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
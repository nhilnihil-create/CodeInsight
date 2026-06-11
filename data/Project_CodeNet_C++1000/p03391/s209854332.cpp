#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		/*
		UL Q; cin >> Q;
		rep(i, Q) {
			ULL A, B; cin >> A >> B;
			ULL S = A * B - 1;
			ULL l = 1, r = S + 1;
			while (l < r - 1) {
				ULL m = (l + r) / 2;
				if (m * m <= S) l = m;
				else r = m;
			}
			ULL ans = l * 2;
			if (l * (l + 1) > S) ans--;
			if (S / A != S / (A + 1)) ans--;
			if (S / B != S / (B + 1)) ans--;
			cout << ans << endl;
		}*/
		UL N; cin >> N;
		ULL ans = 0;
		UL d = 1000000001;
		rep(i, N) {
			UL a, b; cin >> a >> b;
			ans += a;
			if (a > b) d = min(d, b);
		}
		if (d == 1000000001) ans = 0;
		else ans -= d;
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

#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		ULL N; cin >> N;
		ULL ans = 0;
		for (ULL i = 1; i* i < N; i++) {
			if ((N - i) % i == 0)
				if ((N - i) / i > i) ans += (N - i) / i;
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
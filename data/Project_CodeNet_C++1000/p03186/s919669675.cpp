#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL a, b, c; cin >> a >> b >> c;
		UL ans = 0;
		UL buf = min(b, c); b -= buf; c -= buf; ans += buf * 2;
		buf = min(a, c); a -= buf; c -= buf; ans += buf;
		ans += b;
		if (c) ans += 1;
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
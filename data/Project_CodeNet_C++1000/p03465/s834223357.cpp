#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {

	void Solve() {
		bitset<2000001> V;
		UL N; cin >> N;
		V.set(0, true);
		UL S = 0;
		rep(i, N) {
			UL a; cin >> a;
			V |= (V << a);
			S += a;
		}
		UL ans = 0;
		for (UL i = S / 2; i != -1; i--) {
			if (V.test(i)) { ans = i; break; }
		}
		ans = S - ans;
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

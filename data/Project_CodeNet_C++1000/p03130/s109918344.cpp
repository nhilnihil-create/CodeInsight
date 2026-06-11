#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL E[4] = {};
		rep(i, 6) {
			UL e; cin >> e; e--;
			E[e]++;
		}
		sort(E, E + 4);
		if (E[0] == 1 && E[1] == 1 && E[2] == 2) cout << "YES" << endl;
		else cout << "NO" << endl;
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
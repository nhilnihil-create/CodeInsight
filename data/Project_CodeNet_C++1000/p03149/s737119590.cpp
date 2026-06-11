#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		vector<UL> N(4); rep(i, 4) cin >> N[i];
		sort(N.begin(), N.end());
		if (N == vector<UL>({ 1,4,7,9 })) cout << "YES" << endl;
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
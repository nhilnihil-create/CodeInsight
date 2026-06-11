#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		ULL K, A, B; cin >> K >> A >> B;
		ULL N = 1;
		if (A - 1 > K) { cout << (K + 1) << endl; return; }
		if (B < A + 2) { cout << (K + 1) << endl; return; }
		K -= (A - 1);
		N += (A - 1);

		if (K % 2 == 1) { K--; N++; }
		K /= 2;
		N += (B - A) * K;
		cout << N << endl;
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
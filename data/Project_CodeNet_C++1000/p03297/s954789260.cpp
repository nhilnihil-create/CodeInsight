#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	ULL gcd(ULL a, ULL b) { return b ? gcd(b, a % b) : a; }

	void Loop() {
		ULL A, B, C, D; cin >> A >> B >> C >> D;
		if (D < B || A < B) { cout << "No" << endl; return; }
		{
			ULL G = gcd(B, D);
			B /= G; D /= G;
			if (A % G <= C % G) {
				A /= G; C /= G;
			}
			else {
				A /= G; C /= G;
				if (C == 0) { cout << "No" << endl; return; }
				C--;
			}
			A /= G;
		}
		if (C + 1 < B) { cout << "No" << endl; return; }
		cout << "Yes" << endl;
	}

	void Solve(){
		UL t; cin >> t; rep(i, t) Loop();
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
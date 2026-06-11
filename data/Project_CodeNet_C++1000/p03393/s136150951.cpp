#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		string S; cin >> S;
		if (S.size() != 26) {
			bool f[26] = {};
			rep(i, S.size()) { f[S[i] - 'a'] = true; }
			rep(i, 26) { if (!f[i]) { S.push_back('a' + i); cout << S << endl; return; } }
		}
		char c = 'a' - 1;
		bool f[26] = {};
		while(S.size()) {
			if (S.back() < c) {
				for (int i = 25; i > S.back() - 'a'; i--) { if (f[i]) { c = 'a' + i; } }
				S.back() = c;
				cout << S << endl; return;
			}
			c = S.back();
			f[c - 'a'] = true;
			S.pop_back();
		}
		cout << -1 << endl;
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
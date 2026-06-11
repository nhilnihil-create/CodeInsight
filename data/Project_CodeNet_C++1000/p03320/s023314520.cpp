#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	ULL pow10[19] = {
		1, 10, 100, 1000, 10000,
		100000, 1000000, 10000000, 100000000,
		1000000000, 10000000000, 100000000000, 1000000000000,
		10000000000000, 100000000000000, 1000000000000000, 10000000000000000,
		100000000000000000, 1000000000000000000
	};

	void Solve() {
		ULL K; cin >> K;
		vector<ULL> ans;
		pair<ULL, ULL> buf = { 1000000000000000, 1 };
		for (int d = 15; d >= 4; d--) {
			ULL off = pow10[d - 4];
			for (ULL i = 9999; i > 1000; i--) {
				pair<ULL, ULL> Sbuf = {
					i * off + off - 1,
					i / 1000 + i / 100 % 10 + i / 10 % 10 + i % 10 + 9 * (d - 4)
				};
				if (buf.first * Sbuf.second >= Sbuf.first * buf.second) {
					ans.push_back(Sbuf.first);
					//cout << buf.first << "/" << buf.second << "<="
					//	<< Sbuf.first << "/" << Sbuf.second << endl;
					buf = Sbuf;
				}
			}
		}
		for (ULL i = 999; i > 0; i--) {
			pair<ULL, ULL> Sbuf = { i, i % 100 + i / 10 % 10 + i % 10 };
			if (buf.first * Sbuf.second >= Sbuf.first * buf.second) {
				ans.push_back(Sbuf.first);
				//cout << buf.first << "/" << buf.second << "<="
				//	<< Sbuf.first << "/" << Sbuf.second << endl;
				buf = Sbuf;
			}
		}
		reverse(ans.begin(), ans.end());
		rep(i, K) cout << ans[i] << endl;
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

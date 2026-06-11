#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL K; cin >> K;
		vector<UL> V(max(10u, K), -1);
		priority_queue<pair<UL, UL>, vector<pair<UL, UL>>, greater<pair<UL, UL>>> Q;
		Q.push({ 0, 0 });
		while (Q.size()) {
			UL z = Q.top().first, p = Q.top().second; Q.pop();
			if (z > 15) continue;
			if (V[p] != -1) continue;
			V[p] = z;
			rep(i, 10) {
				UL e = p + K * i;
				UL ez = z + e % 10;
				e /= 10;
				Q.push({ ez, e });
			}
		}
		UL ans = 0;
		UL buf = K; while (buf > 0) { ans += buf % 10; buf /= 10; }
		for (UL i = 1; i < 10; i++) {
			if (V[i] == -1) continue;
			ans = min(ans, V[i] + i);
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

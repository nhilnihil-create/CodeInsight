
#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;

unsigned n;
vector<vector<unsigned>> e;

unsigned ans = 0;
unsigned solve2(unsigned p, unsigned pre) {
	unsigned first = 0, second = 0;
	for (auto next : e[p]) {
		if (next == pre) continue;
		unsigned d = solve2(next, p);
		second = max(second, min(first, d));
		first = max(first, d);
	}
	ans = max(ans, first + second + 1);
	return first + 1;
}

void solve() {
	cin >> n;
	e.resize(n);
	rep(i, n - 1) {
		unsigned a, b; cin >> a >> b;
		a--; b--;
		e[b].push_back(a);
		e[a].push_back(b);
	}
	ans = max(ans, solve2(0, (unsigned)-1));

	if (ans % 3 == 2) cout << "Second" << endl;
	else cout << "First" << endl;
}

int main() {

	solve();

	return 0;
}


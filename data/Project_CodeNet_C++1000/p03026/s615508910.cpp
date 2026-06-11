#include<bits/stdc++.h>
using namespace std;


#define rep(i, n) for(int i = 0; i < (n); i++)
using ULL = unsigned long long;


vector<int> p[10000];
int h[10000];

void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b;
		p[a-1].push_back(b-1);
		p[b-1].push_back(a-1);
	}

	int c[10000];
	rep(i, n) cin >> c[i];
	sort(c, c + n);
	int cp = n - 1;

	int ans[10000];
	long long M = 0;

	stack<int> s;
	s.push(0); h[0] = -1;
	while (!s.empty()) {
		int q = s.top(); s.pop();
		rep(i, p[q].size()) {
			if (p[q][i] == h[q]) continue;
			h[p[q][i]] = q;
			s.push(p[q][i]);
		}
		ans[q] = c[cp];
		cp--;
	}

	for (int i = 0; i < n - 1; i++) {
		M += c[i];
	}

	cout << M << endl;
	rep(i, n) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
}

int main() {

	solve();

	return 0;
}
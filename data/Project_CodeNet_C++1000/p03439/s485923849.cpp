#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int q(int x) {
	if (dp[x]) return dp[x];
	cout << x << endl;
	string s; cin >> s;
	if (s == "Vacant") exit(0);
	if (s == "Male") return dp[x] = -1;
	return dp[x] = 1;
}

bool f(int s, int t) {
	int o = (s - t) & 1;
	if (o) return q(s) == q(t);
	return q(s) != q(t);
}

int main() {
	int N;cin >> N;
	dp.resize(N);
	vector<int> v(2*N);
	for (int i = 0; i < N; i++) v[i] = v[i+N] = i;
	int s = 0, t = N / 2;
	if (!f(s, t)) swap(s, t);
	for (;;) {
		if (s > t) {
			int m = v[(s+t+N)/2];
			if (f(s, m)) t = m;
			else s = m;
		} else {
			int m = (s+t)/2;
			if (f(s, m)) t = m;
			else s = m;
		}
	}
}
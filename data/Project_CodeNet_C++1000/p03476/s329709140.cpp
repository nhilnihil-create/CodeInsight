#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX_N = 100005;

bool is_prime(int x) {
	if (x == 2) return true;
	if (x < 2 || x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	vector<bool> ok(MAX_N);
	rep(i, MAX_N) if (is_prime(i)) ok[i] = true;
	vector<int> s(MAX_N);
	rep(i, MAX_N - 1) {
		if (ok[i] && ok[(i + 1) / 2]) s[i + 1] = s[i] + 1;
		else s[i + 1] = s[i];
	}
	int q;
	cin >> q;
	rep(i, q) {
		int l, r;
		cin >> l >> r;
		cout << s[r + 1] - s[l] << endl;
	}
	return 0;
}
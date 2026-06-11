#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1LL << 60;

bool is_prime(int n) {
	if (n < 2) return false;
	if (n > 2 && n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	vector<int> s(100005);
	rep(i, 100005) {
		if (is_prime(i) && is_prime((i + 1) / 2)) s[i + 1] = s[i] + 1;
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
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	vector<int> is_prime(100001, 1);
	is_prime[0] = 0;
	is_prime[1] = 0;
	for (int i = 2; i <= 100000; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= 100000; j += i) is_prime[j] = 0;
	}
	vector<int> a(100001);
	for (int i = 0; i <= 100000; i++) {
		if (i % 2 == 0) continue;
		if (is_prime[i] && is_prime[(i + 1) / 2]) a[i] = 1;
	}
	vector<int> s(100001);
	for (int i = 0; i <= 100000; i++) s[i + 1] = s[i] + a[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		r++;
		cout << s[r] - s[l] << endl;
	}
	return 0;
}
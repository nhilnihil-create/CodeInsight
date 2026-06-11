#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> f(n);
	rep(i, n - 1) if (s[i] == 'A' && s[i + 1] == 'C') f[i] = 1;
	vector<int> t(n + 1);
	rep(i, n) t[i + 1] = t[i] + f[i];
	rep(i, q) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << t[r] - t[l] << endl;
	} 
	return 0;
}
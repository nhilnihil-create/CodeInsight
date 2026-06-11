#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> t = a;
	sort(t.begin(), t.end());
	int c = t[n / 2];
	int d = t[n / 2 - 1];
	rep(i, n) {
		if (a[i] < c) cout << c << endl;
		else cout << d << endl;
	}
	return 0;
}

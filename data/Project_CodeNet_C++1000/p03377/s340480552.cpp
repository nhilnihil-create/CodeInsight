#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
	int a, b, x;
	cin >> a >> b >> x;
	bool ok = (a <= x && x <= a + b);
	cout << (ok ? "YES\n" : "NO\n");
}
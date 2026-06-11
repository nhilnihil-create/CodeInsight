#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
#define X first
#define Y second

int main() {
	int n;
	cin >> n;
	ll a[n], b[n], ans = 0;
	pair<ll, ll> c[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		c[i].X = a[i] + b[i];
		c[i].Y = i;
	}
	sort(c, c + n);
	for(int i = n - 1; i >= 0; i -= 2)
		ans += a[c[i].Y];
	for(int i = n - 2; i >= 0; i -= 2)
		ans -= b[c[i].Y];
	cout << ans ;
}


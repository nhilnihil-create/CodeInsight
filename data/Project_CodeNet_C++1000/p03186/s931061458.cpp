#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 2e6 + 41;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 12;
const int inf = 1e9;

int a[N], p[N];

int main () {
	boost;
	int a, b, c;
	cin >> a >> b >> c;
	int h = min (a, c);
	int ans = h;
	c -= h;
	h = min (b, c);
	ans += h * 2;
	b -= h;
	c -= h;
	cout << ans + b + min (1, c);
}
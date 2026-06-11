#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 41;
const int mod = 1e9 + 7;
const long long INF = 1e16;
const int inf = 1e9;

int main () {
	boost;
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0, h = 0;
	ans = min (a, c);
	c -= ans;
	h = min (b, c);
	ans += 2 * h;
	c -= h;
	b -= h;
	ans += min (1, c);
	cout << ans + b;
}
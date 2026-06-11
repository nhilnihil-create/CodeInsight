#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, w, n, sx, sy;
	string s, t;
	cin >> h >> w >> n;
	cin >> sx >> sy;
	cin >> s >> t;
	bool ans = 0;
	for (int i=0, x=sx; i<n; i++) {
		if (s[i] == 'U') x --;
		if (x <= 0) ans = 1;
		 if (t[i] == 'D') x ++;
		 x = min(x, h);
	}
	for (int i=0, x=sx; i<n; i++) {
		if (s[i] == 'D') x ++;
		if (x > h) ans = 1;
		 if (t[i] == 'U') x --;
		 x = max(1, x);
	}
	for (int i=0, y=sy; i<n; i++) {
		if (s[i] == 'L') y --;
		if (y <= 0) ans = 1;
		 if (t[i] == 'R') y ++;
		 y = min(w, y);
	}
	for (int i=0, y=sy; i<n; i++) {
		if (s[i] == 'R') y ++;
		if (y > w) ans = 1;
		 if (t[i] == 'L') y --;
		 y = max(y, 1);
	}
	cout << (ans ? "NO" : "YES");
	return 0;
}

// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 9;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 8e3 + 5, M = 2 * N;

bitset<2 * M> dpx, dpy;

int main() {
 
	sync;

	string s; cin >> s; s += 'T'; dpx[M] = dpy[M] = true;
	int x, y, d = 0; cin >> x >> y;
	bool up = false, flag = false;
	for (char c : s) {
		if (c == 'F') { d++; continue; }
		if (up) dpy = (dpy << d) | (dpy >> d);
		else if (flag) dpx = (dpx << d) | (dpx >> d);
		else x -= d;
		d = 0;
		up ^= 1;
		flag = 1;
	}
	cout << (dpx[M + x] && dpy[M + y] ? "Yes" : "No") << endl;

	return 0;
}

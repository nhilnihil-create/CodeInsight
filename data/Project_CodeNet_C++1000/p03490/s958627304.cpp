#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define ll long long
#define pii pair < int, int >
#define fr first
#define sc second
#define mk make_pair
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define ok puts("ok");
#define whatis(x) cerr << #x << " = " << x << endl;
#define pause system("pause");
#define random rand() ^ (rand() << 5)

const int N = (int)8000 + 7;
const int inf = (int)1e9 + 7;

int shift = 8002;

bitset < N + N > dpx, dpy;
vector < int > dx, dy;

main() {
	string s;
	int x, y;
	cin >> s;
	int n = sz(s);
	scanf("%d %d", &x, &y);
	int res = 0;
	bool fl = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {                           	
			if (!fl) {
				dx.pb(res);
			} else {
				dy.pb(res);
			}
			res = 0;
			fl ^= 1;
		} else {
			res++;
		}
	}
	if (!fl) {
		dx.pb(res);		
	} else {
		dy.pb(res);
	}
	dpx[shift] = 1;
	dpy[shift] = 1;
	dpx = (dpx << dx[0]);
	for (int i = 1; i < sz(dx); i++) {
		int to = dx[i];
		dpx = (dpx >> to) | (dpx << to);
	}
	for (int to : dy) {
		dpy = (dpy >> to) | (dpy << to);
	}
	if (dpx[x + shift] && dpy[y + shift]) {
		puts("Yes");
	} else {
		puts("No");
	}
}


#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 3005;

string s;
int n, pref[2][N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n >> s;

	pref[1][1] = 1;

	for (int i = 2, ptr = 0; i <= n; i++, ptr ^= 1) {
		for (int j = 1; j <= i; j++) {
			int cur;
			if (s[i - 2] == '>') {
				cur = pref[ptr ^ 1][i - 1] - pref[ptr ^ 1][j - 1];
				if (cur < 0) cur += mod;
			}
			else
				cur = pref[ptr ^ 1][j - 1];
			pref[ptr][j] = pref[ptr][j - 1] + cur;
			if (pref[ptr][j] >= mod)
				pref[ptr][j] -= mod;
		}
	}

	cout << pref[n & 1][n];
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}

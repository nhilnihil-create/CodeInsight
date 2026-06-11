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

const int N = 200500;
const int shift = 100001;

int n, a[N], p[N], t[N];

inline void add(int i) {
	for (; i < N; i += i & -i)
		t[i]++;
}

inline int get(int i) {
	int res = 0;
	for (; i >= 1; i -= i & -i)
		res += t[i];
	return res;
}

inline bool check(int x) {
	memset(t, 0, sizeof(t));
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		add(p[i - 1] + shift);
		p[i] = p[i - 1] + (a[i] >= x ? 1 : -1);
		res += get(p[i] + shift);
	}
	return res >= (n * (n + 1ll) / 2 + 1) / 2;
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int l = 1, r = (int)1e9, ans;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	cout << ans;
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}

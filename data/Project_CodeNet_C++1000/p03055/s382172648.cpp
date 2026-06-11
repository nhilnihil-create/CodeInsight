#define y1 askjdkasldjlkasd
#include <bits/stdc++.h>
#undef y1

using namespace std;

#define pb push_back
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define sz(x) (int)x.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while (0)
#endif

double START_TIME;

void exit() {
#ifdef LOCAL	
	cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
#endif	
	exit(0);
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

///////////////////////////////////////////////////

const int MAX = 2e5 + 41;
string F = "First";
string S = "Second";

void print(string s) {
	printf("%s\n", s.c_str());
	exit(0);
} 

int n;
vi e[MAX];
int d[MAX];

void init() {
	d[0] = 1;	
	fi(1, MAX - 1) {
		d[i] = 1 - d[i - 1];
		if (i >= 2) {
			d[i] = max(d[i], 1 - d[i - 2]);
		}
	}
	dbg0(d, 10);
}

int dist0[MAX];
int dist1[MAX];

void dfs(int x, int p, int dist[MAX]) {
	for (int y : e[x]) {
		if (y == p) continue;
		dist[y] = dist[x] + 1;
		dfs(y, x, dist);
	}
}

void solve () {
	if (n == 1)	print(F);
	if (n == 2) print(S);

	dfs(0, -1, dist0);
	pii v1 = mp(-1, -1);
	fi(0, n - 1) {
		v1 = max(v1, mp(dist0[i], i));
	}
	dfs(v1.second, -1, dist1);
	int a = v1.second;
	pii v2 = mp(-1, -1);
	fi(0, n - 1) {
		v2 = max(v2, mp(dist1[i], i));
	}	
	int dm = v2.first;
	dbg(a);
	dbg0(dist1, n);
	dbg(dm);
	if (d[dm]) {
		print(F);
	} else {
		print(S);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	init();	
	scanf("%d", &n);
	fi(0, n - 2) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	solve();

	exit();
	return 0;
}




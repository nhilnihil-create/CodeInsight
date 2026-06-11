#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

void err(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln() {
#ifdef LOCAL	
	fprintf(stderr, "\n");
#endif	
}

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
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

///////////////////////////////////////////////////

const int MAX = 200 * 1000 + 41;

int n, m;
char s[MAX];
int a[MAX];
vi e[MAX];
bool loop[MAX];

int u[MAX][2];

void ok() {
	printf("Yes\n");
	exit();
}

bool dfs(int x, int f) {
	u[x][f] = 1;
	for (int y : e[x]) {
		if (f) {
		  if (a[x] == a[y]) continue;
		  if (u[y][0] == 1) return true;		  
		  if (u[y][0] == 2) continue;
		  if (dfs(y, 0)) return true;
		} else {
			if (a[x] != a[y]) continue;
			if (u[y][1] == 1) return true;		  
		  if (u[y][1] == 2) continue;
			if (dfs(y, 1)) return true;
		}
	}
	u[x][f] = 2;
	return false;
}

bool dfs2(int x, int f) {
	if (loop[x] && f == 0) return 1;
	u[x][f] = 1;

	for (auto y : e[x]) {
		 if (f) {
		  if (a[x] == a[y]) continue;
		  if (u[y][0] == 1) return true;		  
		  if (u[y][0] == 2) continue;
		  if (dfs2(y, 0)) return true;
		} else {
			if (a[x] != a[y]) continue;
			if (u[y][1] == 1) return true;		  
		  if (u[y][1] == 2) continue;
			if (dfs2(y, 1)) return true;
		}
	}

	u[x][f] = 2;
	return false;
}

void solve() {
	memset(u, 0, sizeof(u));
	fi(1, n) {
		if (u[i][0]) continue;
		dbg(i);
		if (dfs(i, 0)) { 
			ok();
		}
	}

	memset(u, 0, sizeof(u));

	fi(1, n) {
		if (u[i][1]) continue;
		if (!loop[i]) continue;
		if (dfs2(i, 1)) ok();
	}

	printf("No\n");
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  fi(1, n) {
  	a[i] = s[i] - 'A';
  }
  vpii edges;
  fi(1, m) {
  	int x, y;
  	scanf("%d %d", &x, &y);
  	if (x > y) swap(x, y);
  	edges.pb(mp(x, y));  	
  }
  sort(edges.begin(), edges.end());
  edges.resize(unique(edges.begin(), edges.end()) - edges.begin());
  for (auto z : edges) {
  	if (z.first == z.second) {
  		loop[z.first] = 1;
  		continue;
  	}
  	e[z.first].pb(z.second);
  	e[z.second].pb(z.first);
  }
	solve();

	exit();
	return 0;
}




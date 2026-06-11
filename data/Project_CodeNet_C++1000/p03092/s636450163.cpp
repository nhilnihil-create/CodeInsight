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

const int MAX = 5e3 + 41;
const ll INF = 1e18;

int n, A, B;
int a[MAX];
int cnt[MAX][MAX];
ll d[MAX][MAX];
int p[MAX];

int getq(int x, int l, int r) {
	int res = cnt[x][r];
	if (l > 0) res -= cnt[x][l - 1];
	return res;
}

void solve () {	
	fi(0, n - 1) p[a[i]] = i;
	fi(0, n - 1) {
		int cur = 0;
		fj(0, n - 1) {
			if (a[j] > i) {
				cur++;
			}
			cnt[i][j] = cur;
		}
	}
	fill_n(&d[0][0], MAX * MAX, INF);	
	d[0][0] = 0;
	fi(0, n - 1) {
		fj(0, n) {
			if (j > p[i]) {
				d[i + 1][j] = min(d[i + 1][j], d[i][j]);
			}	else {
				int q = getq(i, j, p[i] - 1);
				ll v1 = d[i][j] + (ll) q * A;
				ll v2 = d[i][j] + B;
				d[i + 1][j] = min(d[i + 1][j], v2);
				d[i + 1][p[i] + 1] = min(d[i + 1][p[i] + 1], v1);
//				dbg(v1);
//				dbg(v2);
			}
		}
	}
	/*
	fi(0, n - 1) {
		fj(0, n - 1) {
			err("%d %d %lld\n", i, j, d[i][j]);
		}
	}
	*/
	ll ans = INF;
	fi(0, n) ans = min(ans, d[n][i]);
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d %d", &n, &A, &B);		
	fi(0, n - 1) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	solve();

	exit();
	return 0;
}




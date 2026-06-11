#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

vi g[MAXN];
vi sorted;
int ind[MAXN];
int used[MAXN];
int ans[MAXN];

void dfs(int s) {
	used[s] = 1;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!used[to]) {
			dfs(to);
		}
	}
	sorted.pb(s);
}

void solve(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	m += n - 1;
	REP(i, 0, m) {
		scanf("%d%d", &a, &b);
		g[a].pb(b);
	}
	REPN(i, 1, n) {
		if (!used[i]) {
			dfs(i);
		}
	}
	REP(i, 0, n) {
		ind[sorted[i]] = i;
	}
	REPN(i, 1, n) {
		ans[i] = INF;
	}
	REPN(i, 1, n) {
		/*REPN(j, 1, n) {
			printf("%d ", ans[j]);
		}
		putchar('\n');*/
		REP(j, 0, SZ(g[i])) {
			int to = g[i][j];
			ans[to] = min(ans[to], ind[i]);
		}
	}
	REPN(i, 1, n) {
		if (ans[i] == INF) {
			printf("0\n");
		} else {
			printf("%d\n", sorted[ans[i]]);
		}
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

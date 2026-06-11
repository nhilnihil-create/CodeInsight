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
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

vi g[MAXN];
int p[MAXN];
int v[MAXN];
int used[MAXN];
int top = 1;

void dfs(int s) {
	used[s] = 1;
	v[s] = p[top++];
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!used[to]) {
			dfs(to);
		}
	}
}

void solve(){
	int n, a, b;
	scanf("%d", &n);
	REP(i, 1, n) {
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	REPN(i, 1, n) {
		scanf("%d", &p[i]);
	}
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	dfs(1);
	int sum = 0;
	REPN(i, 2, n) {
		sum += p[i];
	}
	printf("%d\n", sum);
	REPN(i, 1, n) {
		printf("%d ", v[i]);
	}
	putchar('\n');
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

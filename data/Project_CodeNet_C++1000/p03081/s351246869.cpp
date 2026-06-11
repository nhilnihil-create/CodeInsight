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

char s[MAXN];
int n, q;
char sym[MAXN][2], t[MAXN][2];

int process(int pos) {
	REP(i, 0, q) {
		if (s[pos] == sym[i][0]) {
			if (t[i][0] == 'L') {
				pos--;
			} else if (t[i][0] == 'R') {
				pos++;
			}
		}
	}
	return pos;
}

void solve(){
	scanf("%d%d%s", &n, &q, &s[1]);
	REP(i, 0, q) {
		scanf("%s%s", &sym[i][0], &t[i][0]);
	}
	int l1 = 0, r1 = n + 1;
	for(; l1 + 1 < r1; ) {
		int m = (l1 + r1) / 2;
		int v = process(m);
		if (v == 0) {
			l1 = m;
		} else {
			r1 = m;
		}
	}
	int l2 = 0, r2 = n + 1;
	for(; l2 + 1 < r2; ) {
		int m = (l2 + r2) / 2;
		int v = process(m);
		if (v <= n) {
			l2 = m;
		} else {
			r2 = m;
		}
	}
	printf("%d\n", r2 - l1 - 1);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

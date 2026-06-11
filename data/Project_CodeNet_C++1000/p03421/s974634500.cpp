#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
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
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;

vector<vi> ans;
vi tmp;
vi vv;

void solve(){
	ll n, a, b;
	cin >> n >> a >> b;
	if (a * b < n || a + b > n + 1) {
		printf("-1\n");
		return;
	}
	for(int i = 1; i <= n; i += a) {
		vv.pb(i);
	}
	int cnt = 0;
	int fl = 0;
	REP(i, 0, SZ(vv)) {
		int nxt = n;
		if (i < SZ(vv) - 1) {
			nxt = vv[i + 1] - 1;
		}
		tmp.clear();
		REPN(j, vv[i], nxt) {
			tmp.pb(j);
			cnt++;
			if (n - cnt + SZ(ans) + 1 == b) {
				fl = j + 1;
				break;
			}
		}
		ans.pb(tmp);
		if (fl > 0) {
			break;
		}
	}
	if (fl > 0) {
		REPN(i, fl, n) {
			tmp.clear();
			tmp.pb(i);
			ans.pb(tmp);
		}
	}
	for(int i = SZ(ans) - 1; i >= 0; i--) {
		REP(j, 0, SZ(ans[i])) {
			printf("%d ", ans[i][j]);
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

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

const int MAXN = 1e6 + 5;
const int MAXLOG = 45;

ll sum[MAXN];

ll vv[MAXN];
int top_vv;

int good[MAXN];

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	REPN(i, 1, n) {
		int a;
		scanf("%d", &a);
		sum[i] = sum[i - 1] + a;
	}
	REPN(i, 1, n) {
		REPN(j, i, n) {
			vv[top_vv++] = sum[j] - sum[i - 1];
		}
	}
	REP(i, 0, top_vv) {
		good[i] = 1;
	}
	ll ans = 0ll;
	for(int i = MAXLOG; i >= 0; i--) {
		int cnt = 0;
		ll mask = (1ll << i);
		REP(j, 0, top_vv) {
			if (good[j] && (vv[j] & mask)) {
				cnt++;
			}
		}
		if (cnt >= k) {
			ans |= mask;
			REP(j, 0, top_vv) {
				if (good[j] && !(vv[j] & mask)) {
					good[j] = 0;
				}
			}
		}
	}
	printf("%lld\n", ans);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

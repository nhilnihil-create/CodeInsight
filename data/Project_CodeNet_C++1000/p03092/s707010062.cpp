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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const int MAXN = 5e3 + 5;

int per[MAXN];
ll dp[MAXN][MAXN];

void solve(){
	int n;
	ll a, b;
	cin >> n >> a >> b;
	REPN(i, 1, n) {
		cin >> per[i];
	}
	REPN(i, 1, n) {
		REPN(j, 0, n) {
			dp[i][j] = INF;
		}
	}
	REPN(i, 1, n) {
		dp[i][0] = a * i;
	}
	REP(i, 0, n) {
		REPN(j, 0, n) {
			if (dp[i][j] == INF) {
				continue;
			}
			if (per[i + 1] > j) {
				dp[i + 1][per[i + 1]] = min(dp[i + 1][per[i + 1]], dp[i][j]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a);
			} else {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
			}
		}
	}
	ll ans = INF;
	REPN(i, 0, n) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

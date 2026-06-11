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

const int MAXN = (1 << 18) + 5;

int v[MAXN];
int dp[MAXN][2];

vi cur;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, 1 << n) {
		scanf("%d", &v[i]);
		dp[i][0] = dp[i][1] = -1;
	}
	dp[0][0] = 0;
	int last = 0;
	REP(i, 1, 1 << n) {
		cur.clear();
		REP(j, 0, n) {
			if (i & (1 << j)) {
				int i1 = i ^ (1 << j);
				REP(k, 0, 2){
					if (dp[i1][k] != -1) {
						cur.pb(dp[i1][k]);
					}
				}
			}
		}
		cur.pb(i);
		REP(k, 0, 2) {
			int maxi = -1;
			REP(j, 0, SZ(cur)) {
				if ((maxi == -1 || v[cur[j]] > v[maxi]) && cur[j] != dp[i][0]) {
					maxi = cur[j];
				}
			}
			dp[i][k] = maxi;
		}
		//printf("%d %d %d\n", i, dp[i][0], dp[i][1]);
		last = max(last, v[dp[i][0]] + v[dp[i][1]]);
		printf("%d\n", last);
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

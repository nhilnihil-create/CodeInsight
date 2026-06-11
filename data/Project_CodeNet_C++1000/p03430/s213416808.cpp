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

const int MAXN = 305;

char s[MAXN];

int dp[MAXN][MAXN][MAXN];

void solve(){
	int n, k;
	scanf("%s%d", &s[0], &k);
	n = strlen(s);
	REP(i, 0, n) {
		dp[i][i][0] = 1;
	}
	REPN(l, 0, k) {
		for(int i = n - 1; i >= 0; i--) {
			if (l > 0) {
				dp[i][i][l] = dp[i][i][l - 1];
			}
			REP(j, i + 1, n) {
				dp[i][j][l] = max(dp[i + 1][j][l], dp[i][j - 1][l]);
				if (l > 0) {
					dp[i][j][l] = max(dp[i][j][l], dp[i][j][l - 1]);
				}
				if (s[i] == s[j]) {
					dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l] + 2);
				} else if (l > 0) {
					dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l - 1] + 2);
				}
			}
		}
	}
	printf("%d\n", dp[0][n - 1][k]);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

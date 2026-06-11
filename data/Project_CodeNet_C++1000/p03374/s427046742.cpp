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

const int MAXN = 2e5 + 5;

ll d[MAXN], v[MAXN];
ll d0[MAXN], v0[MAXN];
ll dp[MAXN];

void solve(){
	int n;
	ll c, ans;
	scanf("%d%lld", &n, &c);
	REPN(i, 1, n) {
		scanf("%lld%lld", &d0[i], &v0[i]);
		d[i] = d0[i];
		v[i] = v0[i];
	}
	ans = 0ll;
	REP(k, 0, 2) {
		ll sum = 0ll;
		REPN(i, 1, n) {
			sum += v[i];
			dp[i] = max(dp[i - 1], sum - 2 * d[i]);
		}
		sum = 0ll;
		for(int i = n; i >= 1; i--) {
			sum += v[i];
			ans = max(ans, sum - (c - d[i]) + dp[i - 1]);
		}
		
		REPN(i, 1, n) {
			d[i] = c - d0[n + 1 - i];
			v[i] = v0[n + 1 - i];
		}
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

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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

int v[MAXN];
ll sum[MAXN];

ll get_sum(int l, int r) {
	return sum[r] - sum[l - 1];
}

ll get_mid_sum(int l, int r) {
	if (get_sum(l, l) >= get_sum(l + 1, r)) {
		return get_sum(l, l);
	}
	/*if (get_sum(r, r) >= get_sum(l, r - 1)) {
		return get_sum(r, r);
	}*/
	int l1 = l, r1 = r;
	for(; l1 + 1 < r1; ) {
		int mid = (l1 + r1) / 2;
		if (get_sum(l, mid) < get_sum(mid + 1, r)) {
			l1 = mid;
		} else {
			r1 = mid;
		}
	}
	ll mn = INF, mins = 0;
	for(int i = max(l, l1 - 3); i <= min(r - 1, l1 + 3); i++) {
		ll cur = abs(get_sum(l, i) - get_sum(i + 1, r));
		if (cur < mn) {
			mn = cur;
			mins = get_sum(l, i);
		}
	}
	return mins;
}

ll vv[4];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%d", &v[i]);
		sum[i] = sum[i - 1] + v[i];
	}
	ll ans = INF;
	REPN(i, 2, n - 2) {
		ll s1 = get_mid_sum(1, i);
		ll s2 = get_mid_sum(i + 1, n);
		vv[0] = s1;
		vv[1] = get_sum(1, i) - s1;
		vv[2] = s2;
		vv[3] = get_sum(i + 1, n) - s2;
		sort(vv, vv + 4);
		ans = min(ans, vv[3] - vv[0]);
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

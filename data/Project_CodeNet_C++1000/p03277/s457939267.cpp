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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;
const int OFFSET = 1e5 + 2;

int v[MAXN];
int sorted[MAXN];
int tmp1[MAXN], tmp2[MAXN];
int *bal1, *bal2;

int n;

ll cur;

void calc(int l, int r, int val) {
	if (l == r) {
		if (v[l] > val) {
			cur++;
		}
		//printf("%d: %d %d -> %d\n", val, l, r, (v[l] > val ? 1 : 0));
		return;
	}
	int mid = (l + r) >> 1;
	calc(l, mid, val);
	calc(mid + 1, r, val);
	int cnt = max(mid - l + 1, r - mid);
	REPN(i, -cnt, cnt) {
		bal1[i] = bal2[i] = 0;
	}
	
	int curl = 0;
	for(int i = mid; i >= l; i--) {
		if (v[i] <= val) {
			curl--;
		} else {
			curl++;
		}
		bal1[curl]++;
	}
	
	int curr = 0;
	for(int i = mid + 1; i <= r; i++) {
		if (v[i] <= val) {
			curr--;
		} else {
			curr++;
		}
		bal2[curr]++;
	}
	
	ll sum = 0;
	REPN(i, -cnt, cnt) {
		sum += bal2[-i];
		cur += sum * bal1[i];
	}
	
	//printf("%d: %d %d %d -> %lld\n", val, l, mid, r, cur);
}

bool check(int val) {
	cur = 0ll;
	calc(0, n - 1, val);
	return 2ll * cur < (ll)n * (ll)(n + 1) / 2ll;
}

void solve(){
	bal1 = &tmp1[OFFSET];
	bal2 = &tmp2[OFFSET];
	
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
		sorted[i + 1] = v[i];
	}
	sort(sorted + 1, sorted + n + 1);
	sorted[0] = sorted[1] - 1;
	sorted[n + 1] = sorted[n] + 1;
	int l = 0, r = n + 1;
	while(l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(sorted[mid])) {
			r = mid;
		} else {
			l = mid;
		}
		//printf("%d %d\n", l, r);
	}
	printf("%d\n", sorted[r]);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

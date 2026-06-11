#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forab(i, a, b) for(int i=(a);i<(b);++i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(),(a).end()
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const double eps = 1e-8;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl

#ifdef CHEN_PC
	#define debug(...) printf(__VA_ARGS__)
#else 
	#define debug(...)
#endif

const int N = 200010;
ll x[N], xx;
ll sum[N];
int n;

ll solve() {
	reverse(x + 1, x + n + 1);
	sum[0] = 0;
	forab (i, 1, n+1) {
		sum[i] = sum[i - 1] + x[i];
	}
	ll ret = 0;
	forab (i, 1, n+1) {
		ret += x[i] * 5 + 2 * xx;
	}
	forab (k, 1, n+1) {
		int m = n / k;
		if (n % k) m++;
		int l = 0;
		int r = k;
		ll val = n * xx + k * xx;
		forn (i, m) {
			int t = 5;
			if (i > 0) {
				t = i * 2 + 3;
			}
			val += (sum[r] - sum[l]) * t;
			l += k;
			r += k;
			if (r > n) {
				r = n;
			}
			if (val > ret) {
				break;
			}
		}
		ret = min(ret, val);
	}
	return ret;
}

int main(int argc, char *argv[]) {
#ifdef CHEN_PC
	freopen("B.in", "r", stdin);
#endif

	while (scanf("%d%lld", &n, &xx) != EOF) {
		forn (i, n) {
			scanf("%lld", x + i + 1);
		}
		ll ret = solve();
		printf("%lld\n", ret);
	}
	return 0;
}


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

const int N = 100010;
const int mod = 1000000007; // 10^9+7
int n;
pair<ll, int> d[N];
int pnt[N];
int cnt[N];
map<ll, int> dic;

int solve() {
    dic.clear();
	sort(d, d + n);
	forn (i, n) {
		pnt[i] = -1;
		cnt[i] = 1;
		dic[ d[i].first ] = i;
	}
	ll dd = 0;
	for (int i = n - 1; i > 0; --i) {
	    dd += cnt[i];
		int delta = n - cnt[i] * 2;
		ll val = d[i].first - delta;
		if (delta == 0 || dic.find(val) == dic.end()) {
			puts("-1");
			return 0;
		}
		pnt[i] = dic[val];
		cnt[ pnt[i] ] += cnt[i];
	}
//    debug("--- %d\n", dd);
	if (dd != d[0].first) {
	    puts("-1");
	    return 0;
	}
	forn (i, n) {
		if (pnt[i] == -1) {
			continue;
		}
		int u = d[i].second;
		int v = d[pnt[i]].second;
		printf("%d %d\n", v, u);
	}
	return 1;
}

int main(int argc, char *argv[]) {
#ifdef CHEN_PC
	freopen("F.in", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF) {
		forn (i, n) {
		    ll tmp;
			scanf("%lld", &tmp);
			d[i] = MP(tmp, i + 1);
		}
		int ret = solve();
//		printf("%d\n", ret);

#ifdef CHEN_PC
        puts("");
#endif

	}
	return 0;
}


#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = 1000000000000ll;
static const int MIN = INT_MIN;
static const LL LMIN = -LINF;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, q;
    cin >> a >> b >> q;
    vector<LL> va(a + 1), vb(b + 1);
    for(int i = 0; i < a; ++i) cin >> va[i]; va[a] = LINF;
    for(int i = 0; i < b; ++i) cin >> vb[i]; vb[b] = LINF;

    LL x;
    LL la, ra, lb, rb;
    while(q--) {
        la = ra = lb = rb = LMIN;
        cin >> x;
        auto ita = lower_bound(all(va), x); ra = *ita;
        auto itb = lower_bound(all(vb), x); rb = *itb;
        if(ita != va.begin()) la = *(ita - 1);
        if(itb != vb.begin()) lb = *(itb - 1);
        LL lmin = min({llabs(x - la) + llabs(la - lb), llabs(x - la) + llabs(la - rb),
                        llabs(x - ra) + llabs(ra - rb), llabs(x - ra) + llabs(ra - lb)});
        LL rmin = min({llabs(x - lb) + llabs(lb - la), llabs(x - lb) + llabs(lb - ra),
                        llabs(x - rb) + llabs(rb - ra), llabs(x - rb) + llabs(rb - la)});
        cout << min(lmin, rmin) << endl;
    }

    return 0;
}


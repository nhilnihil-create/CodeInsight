#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define DOUBLE(d) cout << fixed << setprecision(15) << (d) << endl

const int MAX = 55;

int N, D[MAX];

int solve() {
    vi cnt(13);
    cnt[0] = 2; cnt[12] = 1;
    REP (i, N) cnt[D[i]]++;
    REP (d, 13) if (cnt[d] > 2) return 0;

    vi dec, undec;
    dec.push_back(0);
    if (cnt[12] == 2) dec.push_back(12);
    FOR (d, 1, 12) {
        if (cnt[d] == 2) {
            dec.push_back(d);
            dec.push_back(24-d);
        } else if (cnt[d] == 1) {
            undec.push_back(d);
        }
    }

    int ret = 0;
    REP (state, 1<<undec.size()) {
        int tmp = 100;
        vi ds;
        FORE (d, dec) ds.push_back(d);
        REP (i, undec.size()) {
            if ((state >> i)&1) ds.push_back(undec[i]);
            else ds.push_back(24-undec[i]);
        }
        sort(ALL(ds));
        REP (i, N+1) {
            int diff = abs(ds[i] - ds[(i+1)%(N+1)]);
            CHMIN(tmp, min(diff, 24-diff));
        }
        CHMAX(ret, tmp);
    }
    return ret;
}

int main() {
    cin >> N;
    REP (i, N) cin >> D[i];
    cout << solve() << endl;
}
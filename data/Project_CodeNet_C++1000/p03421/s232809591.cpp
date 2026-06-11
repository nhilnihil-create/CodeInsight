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
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()

const int MAX = 3e5+10;

ll N, A, B;

void solve() {
    bool check = true;
    check &= (A+B <= N+1);
    check &= (A*B >= N);
    if (!check) {
        cout << -1 << endl;
        return;
    }

    viii res;
    REP (a, A) {
        res.PB(MT(2*MAX, a, a));
    }
    REP (b, B-1) {
        res.PB(MT(-2*MAX, -b, A+b));
    }
    FOR (i, A+B-1, N) {
        int k = i-(A+B-1);
        res.PB(MT(MAX-k/(A-1), k%(A-1), i));
    }
    sort(ALL(res));
    vi ans(N);
    REP (i, N) {
        ans[get<2>(res[i])] = i+1;
    }
    REP (i, N) {
        cout << ans[i] << ((i==N-1)?"\n":" ");
    }
}

int main() {
    cin >> N >> A >> B;
    solve();
}

#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N;
    cin >> N;
    string S;
    cin >> S;

    string S1 = string(S.begin(), S.begin() + N), S2 = string(S.begin() + N, S.end());

    vector<pair<string, string>> p;
    REP(i, 1 << N) {
        string r, b;
        REP(j, N) {
            if (i >> j & 1) r.pb(S2[j]);
            else b.pb(S2[j]);
        }

        reverse(ALL(b));

        p.pb({r, b});
    }

    sort(ALL(p));

    ll ans = 0;
    REP(i, 1 << N) {
        string r, b;
        REP(j, N) {
            if (i >> j & 1) r.pb(S1[j]);
            else b.pb(S1[j]);
        }

        reverse(ALL(b));

        auto pp = make_pair(b, r);
        ans += upper_bound(ALL(p), pp) - lower_bound(ALL(p), pp);

    }

    cout << ans << endl;

}

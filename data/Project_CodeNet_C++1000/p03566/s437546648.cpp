
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
    
    int N;
    cin >> N;

    int T[N + 2];
    REP(i, N) cin >> T[i+1];
    T[0] = 0;
    T[N+1] = 0;

    double v[N+2];
    REP(i, N) cin >> v[i+1];
    v[0] = 0;
    v[N+1] = 0;

    double vt[200 * 1000];
    vt[0] = 0;

    int t = 0;
    double ans = 0;
    FOR(n, 1, N+2) {
        REP(_t, 2 * T[n]) {
            ++t;
            vt[t] = vt[t - 1] + 1;

            int ts = 0;
            REP(i, N+2) {
                vt[t] = min(vt[t], v[i] + abs(ts - double(t) / 2));
                if (i == n) vt[t] = min(vt[t], v[i]);

                ts += T[i];
                vt[t] = min(vt[t], v[i] + abs(ts - double(t) / 2));
                if (i == n) vt[t] = min(vt[t], v[i]);
            }

            ans += (vt[t] + vt[t-1]) / float(4);
        }
    }

    cout << fixed << setprecision(20);
    cout << ans << endl;

}

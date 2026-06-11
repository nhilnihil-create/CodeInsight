#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n), sum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = LLINF;
    // [0, i), [i, n)
    for(int i = 0; i <= n; i++) {
        ll Lsum = sum[i];
        ll Rsum = sum[n] - Lsum;
        int it1 = lower_bound(ALL(sum), Lsum / 2) - sum.begin();
        int it2 = lower_bound(ALL(sum), Lsum + Rsum / 2) - sum.begin();
        for(int j = it1 - 1; j <= it1 + 1; j++) {
            for(int k = it2 - 1; k <= it2 + 1; k++) {
                if(0 <= j && j <= i && i + 1 <= k && k <= n) {
                    ll mx = -LLINF;
                    ll mn = LLINF;
                    chmax(mx, max({sum[j], sum[i] - sum[j], sum[k] - sum[i],
                                   sum[n] - sum[k]}));
                    chmin(mn, min({sum[j], sum[i] - sum[j], sum[k] - sum[i],
                                   sum[n] - sum[k]}));
                    chmin(ans, mx - mn);
                }
            }
        }
    }
    cout << ans << endl;
}
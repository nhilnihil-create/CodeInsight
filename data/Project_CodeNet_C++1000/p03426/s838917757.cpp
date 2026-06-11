#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 998244353;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll h, w, d;
    cin >> h >> w >> d;

    vl x(h*w), y(h*w);
    rep(i, h) {
        rep(j, w) {
            ll a;
            cin >> a;
            a--;
            x[a] = i;
            y[a] = j;
        }
    }

    vl dp(h*w);  // dp[i] : i%dからiへの移動コスト
    exrep(i, d, h*w-1) {
        dp[i] = dp[i-d] + abs(x[i] - x[i-d]) + abs(y[i] - y[i-d]);
    }

    ll q;
    cin >> q;

    vl ans(q);
    rep(i, q) {
        ll L, R;
        cin >> L >> R;
        L--;  R--;
        ans[i] = dp[R] - dp[L];
    }

    rep(i, q) {
        out(ans[i]);
    }

    re0;
}
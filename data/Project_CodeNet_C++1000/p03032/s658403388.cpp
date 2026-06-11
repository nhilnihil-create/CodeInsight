#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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
const ll mod = 1000000007;
const ll INF = 1e16;
const double pi = acos(-1);

int main() {
    ll n, k;
    cin >> n >> k;

    vl v(n);
    rep(i, n) {
        cin >> v[i];
    }

    ll ans = -INF;
    exrep(L, 0, n) {
        exrep(R, 0, n) {
            if(L+R > k) {
                continue;
            }
            if(L+R > n) {
                continue;
            }
            ll x = k - (L+R);
            vl w;
            rep(i, L) {
                w.pb(v[i]);
            }
            for(ll i = n-1; i >= n-R; i--) {
                w.pb(v[i]);
            }
            sort(all(w));
            ll now = 0;
            rep(i, w.size()) {
                if(i < x && w[i] < 0) {
                    continue;
                }
                now += w[i];
            }
            chmax(ans, now);
        }
    }

    out(ans);
    re0;
}
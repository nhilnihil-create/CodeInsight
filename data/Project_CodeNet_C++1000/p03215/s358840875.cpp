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
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
typedef vector<vector<P>> vvP;
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
const ll MAX_N = 100010;

int main() {
    ll n, k;
    cin >> n >> k;
    const ll m = n*(n+1)/2;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vl rui(n+1);
    rep(i, n) {
        rui[i+1] = rui[i] + a[i];
    }

    vl v;
    rep(i, n) {
        exrep(j, i+1, n) {
            v.pb(rui[j] - rui[i]);
        }
    }

    ll ans = 0;
    vl dame(m);  // dame[i] : v[i]は使用しないとき1
    for(ll d = 50; d >= 0; d--) {
        ll mask = 1LL<<d;
        ll cnt = 0;
        rep(i, m) {
            if(dame[i]) {
                continue;
            }
            if(v[i] & mask) {
                cnt++;
            }
        }
        if(cnt >= k) {
            ans += mask;
            rep(i, m) {
                if(!(v[i] & mask)) {
                    dame[i] = 1;
                }
            }
        }
    }

    out(ans);
    re0;
}
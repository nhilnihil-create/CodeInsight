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
const ll MAX_N = 100010;
 
int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    vl rui(n+1);
    rep(i, n) {
        cin >> a[i];
        rui[i+1] = rui[i] + a[i];
    }

    vl v;
    rep(L, n) {
        exrep(R, L, n-1) {
            v.pb(rui[R+1] - rui[L]);
        }
    }

    ll m = v.size();
    vl used(m);  // used[i] : v[i]を使用しないなら1
    ll ans = 0;
    for(ll d = 50; d >= 0; d--) {
        ll mask = 1LL<<d;
        ll cnt = 0;
        rep(i, m) {
            if(used[i]) {
                continue;
            }
            if(v[i] & mask) {
                cnt++;
            }
        }
        if(cnt >= k) {
            rep(i, m) {
                if(v[i] & mask) {
                    ;
                }
                else {
                    used[i] = 1;
                }
            }
            ans += mask;
        }
    }
    
    out(ans);
    re0;
}
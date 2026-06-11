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
    ll n, m;
    cin >> n >> m;

    vector<P> p(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(all(p));

    ll ans = 0;
    ll cnt = 0;
    rep(i, n) {
        ll a = p[i].first;
        ll b = p[i].second;
        if(cnt + b > m) {
            ans += a*(m - cnt);
            break;
        }
        else {
            ans += a*b;
            cnt += b;
        }
    }

    out(ans);
    re0;
}
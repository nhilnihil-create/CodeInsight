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
    ll n;
    cin >> n;

    vector<P> red(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        red[i] = make_pair(b, a);
    }
    sort(rall(red));

    vector<P> blue(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        blue[i] = make_pair(a, b);
    }
    sort(all(blue));

    ll ans = 0;
    vl used(n);  // used[j] : j番目の赤い点を使用したら1
    rep(i, n) {
        rep(j, n) {
            if(used[j]) {
                continue;
            }
            if(blue[i].first > red[j].second && blue[i].second > red[j].first) {
                ans++;
                used[j] = 1;
                break;
            }
        }
    }

    out(ans);
    re0;
}
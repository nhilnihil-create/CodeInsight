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

    vector<P> p(n);
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        p[i] = make_pair(d, t);
    }
    sort(rall(p));

    map<ll, ll> mp;
    priority_queue<ll, vector<ll>, greater<ll>> prQ;
    ll ans = 0;
    rep(i, k) {
        ll d = p[i].first;
        ll t = p[i].second;
        ans += d;
        mp[t]++;
        if(mp[t] >= 2) {
            prQ.push(d);
        }
    }
    ll x = mp.size();
    ans += x*x;

    ll now = ans;
    exrep(i, k, n-1) {
        if(prQ.empty()) {
            break;
        }
        ll d = p[i].first;
        ll t = p[i].second;
        if(mp[t] > 0) {
            continue;
        }
        ll z = prQ.top();
        prQ.pop();
        now += d - z;
        now += 2*x + 1;
        mp[t]++;
        x++;
        chmax(ans, now);
    }

    out(ans);
    re0;
}
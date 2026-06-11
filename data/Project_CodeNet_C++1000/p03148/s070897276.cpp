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
typedef vector<vector<pair<ll, ll>>> vvpll;
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

    vector<pair<ll, ll>> p(n);  // p[i] : (おいしさ, ネタの種類)
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        p[i] = make_pair(d, t);
    }
    sort(rall(p));

    map<ll, ll> mp;
    priority_queue<ll, vector<ll>, greater<ll>> prQ;  // 小さい要素から順に取り出す
    ll sumD = 0;
    rep(i, k) {
        sumD += p[i].first;
        mp[p[i].second]++;
        if(mp[p[i].second] >= 2) {
            prQ.push(p[i].first);
        }
    }
    ll x = mp.size();
    ll ans = sumD + x*x;

    exrep(i, k, n-1) {
        if(prQ.empty()) {
            break;   
        }
        mp[p[i].second]++;
        if(mp[p[i].second] >= 2) {
            mp[p[i].second]--;
            continue;
        }
        sumD += p[i].first - prQ.top();
        prQ.pop();
        x++;
        ll now = sumD + x*x;
        chmax(ans, now);
    }

    out(ans);
    re0;
}
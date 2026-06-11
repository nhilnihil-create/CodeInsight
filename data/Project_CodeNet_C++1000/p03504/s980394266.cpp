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
const ll MAX_T = 100010;
 
int main() {
    ll n, C;
    cin >> n >> C;
    
    vvl v(C, vl(MAX_T));  // v[i][j] : チャンネルiで時刻jに番組があるなら1
    rep(loop, n) {
        ll s, t, c;
        cin >> s >> t >> c;
        s--;  c--;
        v[c][s]++;
        v[c][t]--;
    }
    
    rep(i, C) {
        rep(j, MAX_T-1) {
            v[i][j+1] += v[i][j];
        }
    }
 
    ll ans = 0;
    rep(j, MAX_T) {
        ll cnt = 0;
        rep(i, C) {
            if(v[i][j]) {
                cnt++;
            }
        }
        chmax(ans, cnt);
    }
    
    out(ans);
    re0;
}
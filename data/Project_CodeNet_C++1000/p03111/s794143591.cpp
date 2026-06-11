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

ll n, a, b, c;
vl v;
vl L;
ll ans = INF;

void check(vl &v) {
    ll now = 0;
    ll lA = 0, lB = 0, lC = 0;
    rep(i, n) {
        if(v[i] == 1) {
            if(lA > 0) {
                now += 10;
            }
            lA += L[i];
        }
        else if(v[i] == 2) {
            if(lB > 0) {
                now += 10;
            }
            lB += L[i];
        }
        else if(v[i] == 3) {
            if(lC > 0) {
                now += 10;
            }
            lC += L[i];
        }
    }
    if(lA == 0 || lB == 0 || lC == 0) {
        return;
    }
    now += abs(lA - a) + abs(lB - b) + abs(lC - c);
    chmin(ans, now);
}

void dfs(ll depth) {
    if(depth == n) {
        check(v);
        return;
    }
    rep(i, 4) {
        v[depth] = i;
        dfs(depth+1);
    }
}
 
int main() {
    
    cin >> n >> a >> b >> c;

    L.resize(n);
    rep(i, n) {
        cin >> L[i];
    } 

    v.resize(n);
    dfs(0);

    out(ans);
    re0;
}
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
    ll n;
    cin >> n;

    vl b(n);
    rep(i, n) {
        cin >> b[i];
    }

    vl ans;
    while(!b.empty()) {
        ll m = b.size();
        bool ok = false;
        for(ll i = m-1; i >= 0; i--) {
            if(b[i] == i+1) {
                ans.pb(b[i]);
                b.erase(b.begin() + i);
                ok = true;
                break;
            }
        }
        if(ok == false) {
            out(-1);
            re0;
        }
    }

    reverse(all(ans));
    for(auto x : ans) {
        out(x);
    }
    
    re0;
}
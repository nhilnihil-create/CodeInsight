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

ll ceil(ll a, ll b) {  // a÷b以上の最小の整数
    if(b == 0) {
        return 0;
    }
    return (a+b-1)/b;
}
 
int main() {
    ll k;
    cin >> k;

    vl a(k);
    rep(i, k) {
        cin >> a[i];
    }

    if(a[k-1] != 2) {
        out(-1);
        re0;
    }

    vl y(k+1), z(k+1);
    y[k] = z[k] = 2;
    for(ll i = k-1; i >= 1; i--) {
        y[i] = a[i-1]*ceil(y[i+1], a[i-1]);
        ll m = (z[i+1]+a[i])/a[i-1];
        if((z[i+1]+a[i])%a[i-1] == 0) {
            m--;
        }
        z[i] = a[i-1]*m;
        if(y[i] > z[i]) {
            out(-1);
            re0;
        }
    }

    y[0] = y[1];
    z[0] = z[1] + (a[0] - 1);
    
    cout << y[0] << " " << z[0] << endl;
    re0;
}
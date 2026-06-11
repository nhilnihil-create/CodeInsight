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
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
    return x/gcd(x, y)*y;
}

int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    ll g = gcd(n, m);
    ll a = n/g;
    ll b = m/g;
    rep(i, g) {
        if(s[i*a] != t[i*b]) {
            out(-1);
            re0;
        }
    }
    
    out(lcm(n, m));
    re0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

ll a, b, c, d;

ll gcd (ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

void solve() {
    cin >> a >> b >> c >> d;
    if (a < b) {
        cout << "No" << endl;
        return;
    }
    if (b > d) {
        cout << "No" << endl;
        return;
    }
    if (c >= b) {
        cout << "Yes" << endl;
        return;
    }
    ll g = gcd(b, d);
    if (b - g + a%g > c) cout << "No" << endl;
    else cout << "Yes" << endl;
}

int main() {
    int t; cin >> t;
    rep(i,t) solve();
}
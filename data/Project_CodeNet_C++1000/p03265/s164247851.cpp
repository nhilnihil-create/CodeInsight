#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

int main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4;
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    x3 = x2 - dy;
    y3 = y2 + dx;
    x4 = x1 - dy;
    y4 = y1 + dx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
}
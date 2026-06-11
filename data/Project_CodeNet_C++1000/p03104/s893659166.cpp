#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define chmax(x,y) x = max(x, y)
#define chmin(x,y) x = min(x, y)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

ll f(ll a) {
    if(a % 2) {
        ll l = (a + 1) / 2;
        if(l % 2) return 1;
        return 0;
    }
    ll r = a / 2;
    if(r % 2) {
        ll c = (ll) 1 ^ a;
        return c;
    }
    return a;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll x = f(a-1);
    ll y = f(b);
    ll ans = (ll) x^y;
    cout << ans << endl;
    return 0;
}

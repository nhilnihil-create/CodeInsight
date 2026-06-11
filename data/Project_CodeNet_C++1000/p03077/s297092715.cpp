#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll x = min(a, min(b, min(c, min(d, e))));
    cout << (n + x - 1) / x + 4 << endl; 
    return 0;
}

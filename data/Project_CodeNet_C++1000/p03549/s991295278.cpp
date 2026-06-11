#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll solver(ll n, ll m)
{
    ll base = 1900 * m + 100 * (n - m);
    return base * 1 << m;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    cout << solver(n, m) << endl;
}
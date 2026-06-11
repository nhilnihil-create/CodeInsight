#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

void solve(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    cout << accumulate(a.begin(), a.end(), -n) << endl;
}
int main(void) { solve(); }
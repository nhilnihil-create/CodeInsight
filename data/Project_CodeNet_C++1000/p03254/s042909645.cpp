#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    ll sum = 0;
    rep(i, n) {
        sum += a[i];
        if(x >= sum) {
            ans++;
        }
        else {
            cout << ans << endl;
            return 0;
        }
    }
    if(x == sum) cout << n << endl;
    else cout << n - 1 << endl;
    return 0;
}
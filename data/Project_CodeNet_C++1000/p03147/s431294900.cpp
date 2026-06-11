#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int ans = 0;
    int active = 0;
    rep(i, n) {
        if(active >= h[i]) {
            active = h[i];
        }
        else {
            ans += h[i] - active;
            active = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}
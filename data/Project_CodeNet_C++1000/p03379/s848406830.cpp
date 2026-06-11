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
    vector<int> x(n);
    vector<int> y(n);
    rep(i, n) cin >> x[i];
    rep(i, n) y[i] = x[i];
    sort(y.begin(), y.end());
    int sm = y[n / 2];
    int la = y[n / 2 - 1];
    rep(i, n) {
        if(x[i] < sm) cout << sm << endl;
        else cout << la << endl;
    }
    return 0;
}

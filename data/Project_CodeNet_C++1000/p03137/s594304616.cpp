#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    if(n >= m) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> x(m);
    rep(i, m) cin >> x[i];
    sort(x.begin(), x.end());
    int ans = x[m - 1] - x[0];
    vector<int> dx(m - 1);
    rep(i, m - 1) {
        dx[i] = x[i + 1] - x[i];
    }
    sort(dx.begin(), dx.end());
    for(int i = m - 2; i >= m - n; i--) {
        ans -= dx[i];
    }
    cout << ans << endl;
    return 0;
}

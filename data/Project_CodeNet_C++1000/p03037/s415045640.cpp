#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    vector<int> r(m);
    rep(i,m) cin >> l[i] >> r[i];
    int ma = l[0], mi = r[0];
    rep(i,m) {
        ma = max(l[i], ma);
        mi = min(r[i], mi);
    }
    int ans = mi-ma+1;
    if (ans<0) ans = 0;
    if (ans>n) ans = n;
    cout << ans << endl;
    return 0;
}

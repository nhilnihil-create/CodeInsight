#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m,ans;

    cin >> n >> m;
    vector<int> l(m),r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
    }

    int mn = 0;
    int mx = INT_MAX;
    ans = 0;
    rep(i, m) {
        mn = max(mn, l[i]);
        mx = min(mx, r[i]);
    }

    if (mn<=mx)
        ans = mx - mn + 1;
    cout << ans << endl;

    return 0;
}

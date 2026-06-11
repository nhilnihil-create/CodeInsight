#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans=0;
    vector<int> v(n),c(n);
    rep (i, n) cin >> v[i];
    rep (i, n) cin >> c[i];
    rep (i, n) {
        ans += max(0, v[i] - c[i]);
    }
    cout << ans << endl;
    return 0;
}
//----------------------------------------------------------------------
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    rep(i, n) {
        int mid = b[i];
        ll numa = distance(a.begin(), lower_bound(a.begin(), a.end(), mid));
        ll numb = distance(upper_bound(c.begin(), c.end(), mid), c.end());
        ans += numa * numb;
    }
    cout << ans << endl;
    return 0;
}

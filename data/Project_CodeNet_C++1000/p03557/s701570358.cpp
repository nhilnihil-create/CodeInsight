#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
#define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int ans = 0;
    rep(i,n) {
        int mid = b[i];
        int aa = lower_bound(a.begin(),a.end(),mid)-a.begin();
        int cc = c.end()-upper_bound(c.begin(),c.end(),mid); 
        // cout << aa<<" "<<cc << endl;
        ans += (aa)*(cc);
    }
    cout << ans << endl;
    return 0;
}


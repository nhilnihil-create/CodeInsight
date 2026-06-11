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
    int n,m,c;
    cin >> n>> m >> c;
    vector<int> b(m);
    rep(i,m)cin >> b[i];
    int ans = 0;
    rep(i,n) {
        int tmp = c;
        rep(i,m) {
            int a;
            cin >> a;
            tmp += a*b[i];
        }
        if(tmp>0) ans++;
    }
    cout << ans << endl;
    return 0;
}


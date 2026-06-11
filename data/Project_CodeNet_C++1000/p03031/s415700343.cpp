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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<int> p(m);
    rep(i,m) {
        int k;
        cin>> k;
        rep(j,k) {
            int x;
            cin >> x;
            x--;
            a[i].push_back(x);
        }
    }
    rep(i,m) {
        
        cin >> p[i];
    }
    int ans = 0;
    rep(i,1<<n) {
        int cnt = 0;
        rep(j,m) {
            int tm = 0;
            for(auto s: a[j]) {
                int sw = (i>>s)&1;
                tm+=sw;
            }
            if(tm%2==p[j])cnt++;
        }
        if(cnt==m)ans++;
    }
    cout << ans << endl;



    return 0;
}


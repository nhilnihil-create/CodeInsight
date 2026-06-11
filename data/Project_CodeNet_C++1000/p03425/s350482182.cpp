#include <bits/stdc++.h>
#include <vector>
#include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9+5;
const int mod = 1e9+7;
using ll = long long;

signed main(){
    int n;
    cin >> n;
    vector<string> a(n);
    map<char,int> m;
    rep(i,n) {
        cin >> a[i];
        m[a[i][0]]++;
    }
    vector<int> c;
    c.push_back(m['M']);
    c.push_back(m['A']);
    c.push_back(m['R']);
    c.push_back(m['C']);
    c.push_back(m['H']);
    
    int ans = 0;
    rep(i,5) {
        FOR(j,i,5) {
            FOR(k,j,5) {
                if(i==j || j==k || k==i)continue;
                ans += c[i]*c[j]*c[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

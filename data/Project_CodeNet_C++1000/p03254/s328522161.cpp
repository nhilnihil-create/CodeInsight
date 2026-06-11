#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
map<char, int> m;
signed main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    int total = 0;
    int now = 0;
    while(now<n) {
        total += a[now];
        if(total>x) {
            cout << now << endl;
            return 0;
        }
        now++;
    }
    if(total==x) cout << n << endl;
    else cout << n-1 << endl;
  return 0;
}


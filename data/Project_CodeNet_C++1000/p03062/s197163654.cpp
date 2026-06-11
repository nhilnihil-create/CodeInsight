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
const int inf = 1e9;
const int mod = 998244353;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);



signed main(){
    int n;
    cin >> n;
    int mi = inf;
    int ans = 0;
    int cnt = 0;
    rep(i,n) {
        int a;
        cin >> a;
        ans += abs(a);
        if(a<0) cnt++;
        mi = min(mi,abs(a));
    }
    //cout << ans<<" "<<cnt << endl;
    if(cnt%2==1) ans -=abs(mi)*2;
    cout << ans << endl;
    


    return 0;
}


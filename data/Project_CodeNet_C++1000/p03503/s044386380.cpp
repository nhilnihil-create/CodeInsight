#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using vv = vector<v>;

int main(){
    ll n;
    cin >> n;
    
    vv f(n, v(10));
    rep(i,n)rep(j,10)cin >> f[i][j];
    
    vv p(n, v(11));
    rep(i,n)rep(j,11)cin >> p[i][j];
    
    
    ll ans = -2002002002LL;
    for(int k=1; k<1<<10; k++){
        ll now = 0;
        rep(i,n){
            int num = 0;
            rep(j,10){
                if((k & 1<<j) && f[i][j])
                    num++;
            }
            now += p[i][num];
        }
        ans = max(now, ans);
    }
    
    cout << ans << endl;
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n,k; cin >> n >> k;
    vector<ll> x(n),y(n),posx,posy;
    rep(i,n){
        cin >> x[i] >> y[i];
        posx.push_back(x[i]);
        posy.push_back(y[i]);
    }
    sort(ALL(posx));
    sort(ALL(posy));
    ll ans = (posx[n-1] - posx[0]) * (posy[n-1] - posy[0]);
    rep(xl,n){
        FOR(xr,xl+1,n){
            rep(yl,n){
                FOR(yr,yl+1,n){
                    int cnt = 0;
                    rep(i,n) if(posx[xl] <= x[i] && x[i] <= posx[xr] && posy[yl] <= y[i] && y[i] <= posy[yr]) cnt++;
                    if(cnt >= k) ans = min(ans, (posx[xr] - posx[xl]) * (posy[yr] - posy[yl]));
                }
            }
        }
    }
    cout << ans << endl;
}
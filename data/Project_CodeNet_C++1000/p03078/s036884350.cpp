#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
vector<ll> a, b, c;
ll x, y, z, k;

int main(){
    cin >> x >> y >> z >> k;
    a.resize(x); b.resize(y);c.resize(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    auto solve=[&](ll q){
        int cnt = 0;
        rep(i, x){
            rep(j, y){
                rep(w, z){
                    if(a[i]+b[j]+c[w]<q) break;
                    cnt++;
                    if(cnt==k) return true;
                }
            }
        }
        return false;
    };
    ll ng = a[0]+b[0]+c[0]+1, ok=-1;
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        if(solve(mid))ok=mid;
        else ng=mid;
    }
    
    vector<ll> ans;
    rep(i,x)rep(j,y)rep(w,z){
        if(a[i]+b[j]+c[w]<ok) break;
        ans.push_back(a[i]+b[j]+c[w]);
    }
    sort(ans.rbegin(), ans.rend());
    rep(i, k)cout << ans[i] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    map<pair<ll,ll>,ll> mp;
    vector<ll> xv;
    vector<ll> yv;
    for(i = 0;i < n;++i){
        ll x,y;
        cin >> x >> y;
        mp[make_pair(x,y)] = 0;
        xv.push_back(x);
        yv.push_back(y);
    }
    sort(all(xv));
    sort(all(yv));
    vector<vector<ll>> tizu(n+1,vector<ll>(n+1,0));
    for(auto point:mp){
        ll x = point.first.first;
        ll y = point.first.second;
        ll xind = lower_bound(all(xv), x) - xv.begin()+1;
        ll yind = lower_bound(all(yv), y) - yv.begin()+1;
        ++tizu.at(xind).at(yind);
    }
    for(i = 0;i <= n;++i){
        rep(j,n){
            tizu.at(i).at(j+1) += tizu.at(i).at(j);
        }
    }
    for(i = 0;i < n;++i){
        rep(j,n+1){
            tizu.at(i+1).at(j) += tizu.at(i).at(j);
        }
    }
    ll ans = 5e18;
    for(i = 1;i <= n-1;++i){
        for(j = i+1;j <=n;++j){
            ll iy,jy;
            for(iy = 1;iy <= n-1;++iy){
                for(jy = iy+1;jy <=n;++jy){
                    ll num = tizu.at(j).at(jy) - tizu.at(j).at(iy-1) - tizu.at(i-1).at(jy) + tizu.at(i-1).at(iy-1);
                    if(num < k) continue;
                    ll tmp = (xv.at(j-1)-xv.at(i-1))*(yv.at(jy-1) - yv.at(iy-1));
                    ans = min(ans, tmp);
                }   
            }
        }   
    }
    cout << ans << endl;

    return 0;
}
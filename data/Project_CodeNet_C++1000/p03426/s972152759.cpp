#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll h,w,d;
    cin >> h >> w >> d;
    vector<vector<ll>> a(h,vector<ll>(w));
    vector<pair<ll,ll>> mapa(h*w+1); 
    for(i = 0;i < h;++i){
        rep(j,w){
            cin >> a.at(i).at(j);
            mapa.at(a.at(i).at(j)) = make_pair(i,j); 
        }
    }
    vector<ll> ruiseki(h*w+1,0);
    for(i = 1;i <= d;++i){
        for(j = i+d;j <= h*w;j += d){
            ll tmp = abs(mapa.at(j).first - mapa.at(j-d).first) + abs(mapa.at(j).second - mapa.at(j-d).second);
            ruiseki.at(j) = ruiseki.at(j-d) + tmp; 
        }
    }
    ll q;
    cin >> q;
    for(i = 0;i < q;++i){
        ll l,r;
        cin >> l >> r;
        cout << ruiseki.at(r) - ruiseki.at(l) << endl;
    }

    return 0;
}
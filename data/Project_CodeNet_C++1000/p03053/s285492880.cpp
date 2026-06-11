#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll h,w;
    cin >> h >> w;
    vector<string> a(h);
    vector<vector<ll>> kyori(h,vector<ll>(w,-1));
    queue<pair<ll,ll>> que;
    ll ans = 0;
    for(i = 0;i < h;++i){
        cin >> a.at(i);
    }
    for(i = 0;i < h;++i){
        rep(j,w){
            if(a.at(i).at(j) == '#'){
                que.emplace(i,j);
                kyori.at(i).at(j) = 0;
            }
        }
    }
    ll di[4] = {0,-1,1,0};
    ll dj[4] = {-1,0,0,1};
    while(!que.empty()){
        auto x = que.front();
        que.pop();
        ll d = kyori.at(x.first).at(x.second);
        for(i = 0;i < 4;++i){
            ll ni = x.first + di[i];
            ll nj = x.second + dj[i];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(kyori.at(ni).at(nj) == -1){
                kyori.at(ni).at(nj) = d+1;
                que.emplace(ni,nj);
                ans = max(ans, d+1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
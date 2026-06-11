#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll h,w,d;cin>>h>>w>>d;
    ll a[h][w];for(ll i=0;i<h;i++)for(ll j=0;j<w;j++)cin>>a[i][j],a[i][j]--;
    vector< pair<ll , pair<ll,ll> > >pos[d];
    for(ll i=0;i<h;i++)for(ll j=0;j<w;j++)pos[a[i][j]%d].push_back({a[i][j] , {i,j} });
    vector< ll > prfx[d];
    for(ll i=0;i<d;i++){
        sort(pos[i].begin(),pos[i].end());
       // cout<<"I: "<<i<<"-->";
        //for(auto &ele:pos[i])cout<<ele.first<<"-{"<<ele.second.first<<" "<<ele.second.second<<"} ";cout<<endl;
        prfx[i].push_back(0);
        for(ll j=1;j<pos[i].size();j++)
            prfx[i].push_back( abs(pos[i][j].second.first-pos[i][j-1].second.first) + abs(pos[i][j].second.second - pos[i][j-1].second.second));
        for(ll j=1;j<prfx[i].size();j++)prfx[i][j]+=prfx[i][j-1];
       // for(auto &ele:prfx[i])cout<<ele<<" ";cout<<endl;
    }
    ll q;cin>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        l--;r--;
        ll idx = l%d;
        ll s = l/d , e = r/d;
        ll ans = prfx[idx][e]  - prfx[idx][s];
        cout<<ans<<"\n";
    }
}

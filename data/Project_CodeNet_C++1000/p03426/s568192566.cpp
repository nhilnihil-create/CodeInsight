#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll h,w,d;cin>>h>>w>>d;
    pair<ll,ll> a[100010];
    rep(i,0,h){
        rep(j,0,w){
            ll b;cin>>b;
            a[b]=make_pair(i+1,j+1);
        }
    }
    vector<ll> mod[100010];
    rep(i,1,d+1){
        ll j=0;
        while(i+j*d<=h*w){
            if(j==0)mod[i].push_back(0);
            else mod[i].push_back(mod[i][mod[i].size()-1]+abs(a[i+j*d].first-a[i+(j-1)*d].first)+abs(a[i+j*d].second-a[i+(j-1)*d].second));
            j++;
        }
    }
    ll q;cin>>q;
    rep(i,0,q){
        ll x,y;cin>>x>>y;
        ll ama=x%d;
        if(ama==0)ama=d;
        ll l=(x-ama)/d,r=(y-ama)/d;
        cout<<mod[ama][r]-mod[ama][l]<<endl;
    }
}






#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll x,y,z,k;cin>>x>>y>>z>>k;
    ll a[1010],b[1010],c[1010];
    rep(i,0,x)cin>>a[i];
    rep(i,0,y)cin>>b[i];
    rep(i,0,z)cin>>c[i];
    vector<ll> vc,vec;
    rep(i,0,x){
        rep(j,0,y){
            vc.push_back(a[i]+b[j]);
        }
    }
    sort(vc.begin(),vc.end(),greater<>());
    rep(i,0,z){
        rep(j,0,min(x*y,k)){
            vec.push_back(vc[j]+c[i]);
        }
    }
    sort(vec.begin(),vec.end(),greater<>());
    rep(i,0,k){
        cout<<vec[i]<<endl;
    }
}

    








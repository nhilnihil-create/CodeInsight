#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
#define rep(i,l,r) for(ll i=l;i<=r;i++)

ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}
vector<vector<ll>> v1(100010);  //矢印の方向
vector<vector<ll>> v2(100010);  //矢印が入ってくる方向
vector<ll> retu2;
bool seen[100010];

void kiki(ll i){
    for(ll j=0;j<v1[i].size();j++){
        if(seen[v1[i][j]]==false){
            seen[v1[i][j]]=true;
            kiki(v1[i][j]);
        }
    }
    retu2.push_back(i);
}


int main(){
    ll n,m;cin>>n>>m;
    ll a[n+m-1],b[n+m-1];
    rep(i,0,n+m-1-1){
        cin>>a[i]>>b[i];
        v1[a[i]].push_back(b[i]);
        v2[b[i]].push_back(a[i]);
    }
    ll ne=0;
    rep(i,1,n){
        if(v2[i].size()==0){
            ne=i;
        }
    }
    kiki(ne);
    ll retu[n];
    ll ans[n+1];
    ll gya[n+1];
    rep(i,0,n-1){
        retu[i]=retu2[n-1-i];
        gya[retu[i]]=i;
    }
    ll r;
    ll maxi;
    rep(i,0,n-1){
        r=retu[i];
        if(v2[r].size()==0){
            ans[r]=0;
        }else if(v2[r].size()==1){
            ans[r]=v2[r][0];
        }else{
            maxi=-1;
            rep(j,0,v2[r].size()-1){
                maxi=max(maxi,gya[v2[r][j]]);
            }
            ans[r]=retu[maxi];
        }
    }
    rep(i,1,n){
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}

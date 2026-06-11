#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;

using namespace std;
int main(){
    cs;
    int x,y,z,K,t=0;
    cin>>x>>y>>z>>K;
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    rep(i,x) cin>>a[i];
    rep(i,y) cin>>b[i];
    rep(i,z) cin>>c[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    vector<ll> ans(1000000);
    rep(i,x){
        rep(j,y){
            rep(k,z){
                if((i+1)*(j+1)*(k+1)<=K) 
                {ans[t]=a[i]+b[j]+c[k];t++;}
            }
        }
    }
    sort(ans.begin(),ans.begin()+t,greater<>());
    rep(i,K) cout<<ans[i]<<'\n';
}
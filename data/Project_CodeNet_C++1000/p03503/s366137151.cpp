#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

const ll INF=1e9;

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> f(n,vector<ll>(10)),p(n,vector<ll>(11));
    rep(i,n)rep(j,10) cin>>f[i][j];
    rep(i,n)rep(j,11) cin>>p[i][j];
    ll mx=-INF;
    for(ll t=1;t<(1<<10);t++){
        ll sum=0;
        rep(i,n){
            ll cnt=0;
            rep(j,10){
                if((t>>j)&f[i][j]) cnt++;
            }
            sum+=p[i][cnt];
        }
        mx=max(mx,sum);
    }
    cout<<mx<<endl;
    return 0;
}
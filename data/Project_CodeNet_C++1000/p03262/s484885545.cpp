#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
ll gcd(ll a,ll b){
    if(b==0){return a;}
    else{return gcd(b,a%b);}
}
int main(){
    ll n,x;cin>>n>>x;
    vector<ll> xvec(n);
    vector<ll> minus(n);
    rep(i,n) cin>>xvec[i];
    xvec.push_back(x);
    sort(xvec.begin(),xvec.end());

    rep(i,n) minus[i]=xvec[i+1]-xvec[i];

    if(n==1){
        cout<<abs(minus[0])<<endl;
        return 0;
    }
    ll ans=gcd(minus[0],minus[1]);
    rep(i,n-1){
        ans=gcd(ans,minus[i]);
    }

    cout<<ans<<endl;
    return 0;
}
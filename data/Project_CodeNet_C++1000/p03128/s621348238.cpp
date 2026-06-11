#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    ll INF=1001001001;
    ll n,m; cin>>n>>m;
    vector<ll> nes={0,2,5,5,4,5,6,3,7,6};
    vector<ll> a(m);
    rep(i,m) cin>>a[i];
    vector<ll> dp(n+1,(-1)*INF);
    dp[0]=0;
    rep(i,n){
        rep(j,m){
            if(i+1-nes[a[j]]<0)continue;
            chmax(dp[i+1],dp[i+1-nes[a[j]]]+1);
        }
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll nn=dp[n];
    rep(i,nn){
        rep(j,m){
            if(n-nes[a[j]]>=0 && dp[n-nes[a[j]]]==dp[n]-1){cout<<a[j]; n-=nes[a[j]]; break;}
        }
    }
    cout<<endl;
}
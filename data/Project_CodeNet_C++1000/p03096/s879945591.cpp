#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,n) REP(i,0,n)
#define pb push_back

ll dp[200001];
vec Col[200001];
ll Cdp[200001];

int main(){
    ll N; cin>>N;
    vec D(N);
    rep(i,N) cin>>D.at(i);
    vec C;
    C.pb(D.at(0));
    REP(i,1,N) if(D.at(i)!=D.at(i-1)) C.pb(D.at(i));
    ll M=C.size();
    rep(i,M) Col[C.at(i)].pb(i);
    dp[M]=1;
    REP2(i,M-1,0){
        ll x=C.at(i);
        dp[i]=(dp[i+1]+Cdp[x])%mod;
        Cdp[x]=dp[i];   
    }
    cout<<dp[0]<<endl;


}
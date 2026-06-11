#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
vector<ll>dp(200010,-1);
vector<ll>c(200010);
vector<ll>nxt(200010,inf);
ll solve(ll i){
    if(dp[i]>=0)return dp[i];
    if(nxt[i]==i+1){
        dp[i]=solve(i+1);
    }
    else if(nxt[i]==inf){
        dp[i]=solve(i+1);
    }else{
        dp[i]=(solve(i+1)+solve(nxt[i]))%inf;
    }
    return dp[i];
}
int main(){
    ll n;cin>>n;
    rep(i,n){
        cin>>c[i];
    }
    dp[n-1]=1;
    vector<ll>last(200010,inf);
    for(int i=n-1;i>=0;i--){
        nxt[i]=last[c[i]];
        last[c[i]]=i;
    }
    ll ans=solve(0);
    cout<<ans<<endl;
}
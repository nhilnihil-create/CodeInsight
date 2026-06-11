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
const ll mod=998244353;
ll n;
vector<vector<ll> >a(17,vector<ll>(17));
vector<ll>dp(100010,-1);
ll solve(ll k){
    if(dp[k]>=0)return dp[k];
    ll ma=0;
    rep(i,n){
        REP(j,i+1,n){
            if(((1<<i)&k)&&((1<<j)&k)){
                ma+=a[i][j];
            }
        }
    }
    for(int i=k;;){
        i=(i-1)&k;
        if(i==0)break;
        ma=max(solve(i)+solve(k-i),ma);
    }
    dp[k]=ma;
    return dp[k];
}
int main(){
    cin>>n;
    rep(i,n)rep(j,n)cin>>a[i][j];
    rep(i,n)dp[1<<i]=0;
    solve((1<<n)-1);
    cout<<dp[(1<<n)-1]<<endl;
}
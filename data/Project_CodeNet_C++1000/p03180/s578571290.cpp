#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
//const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[(1<<16)+10];
ll memo[(1<<16)+10];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<16);i++)dp[i]=-inf;
    dp[0]=0;
    V<V<ll>> d(n,V<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>d[i][j];
    }
    for(int bit=0;bit<(1<<n);bit++){
        ll res=0;
        for(int j=0;j<n;j++){
            if(~bit&(1<<j))continue;
            for(int k=j+1;k<n;k++){
                if(~bit&(1<<k))continue;
                res+=d[j][k];
            }
        }
        memo[bit]=res;
    }
    for(int i=0;i<=n;i++){
        for(int bit=0;bit<(1<<n);bit++){
            if(__builtin_popcount(bit)!=i)continue;
            for(int j=0;j<n;j++){
                if(~bit&(1<<j)){
                    chmax(dp[bit^(1<<j)],dp[bit]+dp[0]);
                    for(int s=bit;s>0;s=(s-1)&bit){
                        chmax(dp[bit^(1<<j)],dp[s^bit]+memo[s^(1<<j)]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
}
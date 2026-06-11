#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 100009 /// I wanna be the wind
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e17 + 9;
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll fastpow(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc=mult(calc,a);
        a=mult(a,a);
    }
    return calc;
}
ll soma(ll a,ll b){
    if(a+b>MOD)return a+b-MOD;
    else return a+b;
}
ll subt(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}
ll mat[22][22];
ll dp[22][1<<21];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    rep(i,1,n+1){
        rep(j,1,n+1){
            cin>>mat[i][j];
        }
    }
    rep(i,0,22){
        rep(j,0,1<<n){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    rep(i,1,n+1){
        rep(j,0,1<<n){
            if(__builtin_popcount(j)!=i-1)continue;
            rep(k,1,n+1){
                ll nst = j|(1<<(k-1));
                if(j^(1<<(k-1)) && mat[i][k]==1) dp[i][nst]=soma(dp[i][nst],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][(1<<(n))-1]<<"\n";
    return 0;  
}
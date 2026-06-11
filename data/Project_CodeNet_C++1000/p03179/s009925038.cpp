#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 3009 /// I wanna be the wind
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
ll add_self(ll &a,ll b){
    a+=b;
    if(a>=MOD)a-=MOD;
    return a;
}
ll subt(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}
vector<ll> dp(maxn,0);
vector<ll> prefix(maxn,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    dp[1] = 1;
    rep(i,2,n+1){ /// position we are now
        vector<ll> new_dp(i+2,0);
        rep(j,1,i+1){
            prefix[j] = (prefix[j-1]+dp[j])%MOD;
        }
        rep(j,1,i+1){   /// number that I will put now
            ll L,R;
            if(s[i-2] == '<'){
                L = 1;
                R = j-1;
            }
            else{
                L = j;
                R = i-1;
            }
            if(L>R){
                continue;
            }
            // cout<<L-1<<" "<<R<<" "<<prefix[R]<<" "<<prefix[L-1]<<"\n";
            add_self(new_dp[j],(prefix[R]-prefix[L-1]+MOD)%MOD);
        }
        dp = new_dp;
    }
    ll ans = 0;
    rep(i,1,n+1){
        add_self(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;  
}   
#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I wanna be the wind
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
ll vet[maxn],segt[4*maxn];
void build(ll id ,ll l,ll r){
    if(l==r)segt[id]=vet[l];
    else{
        ll mid=(l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        segt[id]=segt[id<<1]+segt[id<<1|1];
    }
}
void update(ll id,ll l,ll r,ll pos,ll val){
    if(l==r){
        segt[id]=val;
    }
    else{
        ll mid=(l+r)>>1;
        if(pos<=mid)update(id<<1,l,mid,pos,val);
        else update(id<<1|1,mid+1,r,pos,val);
        segt[id] = max(segt[id<<1],segt[id<<1|1]);
    }
}
ll query(ll id,ll l,ll r,ll x,ll y){
    if(x<=l && r<=y)return segt[id];
    else if(l>y || r<x)return 0;
    else{
        ll mid=(l+r)>>1;
        return max(query(id<<1,l,mid,x,y),query(id<<1|1,mid+1,r,x,y));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> h(n),b(n);
    rep(i,0,n){
        cin>>h[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    ll dp[maxn];
    memset(dp,0,sizeof dp);
    rep(i,0,n){
        dp[i] = b[i];
    }
    rep(i,0,n){
        dp[i] = max(query(1,1,n,1,h[i]-1)+b[i],dp[i]);
        update(1,1,n,h[i],dp[i]);
    }
    ll ans=0;
    rep(i,0,n+2){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
    return 0;  
}   
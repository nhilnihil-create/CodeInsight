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
vector<int> adj[maxn];
pii dfs(int v, int p){
    ll allwhite = 1;
    ll stblack = 0;
    for(auto e: adj[v]){
        if(e==p){
            continue;
        }
        pii res = dfs(e,v);
        ll antwhite = allwhite;
        allwhite = mult(allwhite,res.second);
        stblack = soma(mult(stblack, soma(res.first, res.second)), mult(antwhite, res.first));
    }
    return {allwhite,soma(allwhite, stblack)};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll m = n-1;
    while(m--){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pii ans = dfs(1,-1);
    ll ansf = soma(ans.F,ans.S);
    cout<<ansf<<"\n";
    return 0;  
}
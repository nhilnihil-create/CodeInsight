//Even Relation

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<P>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

graph g;

vector<int>ans;

//現在・一個前・色
void dfs(int v,int p,int c){
    ans[v]=c;
    for(auto i:g[v]){
        if(i.first==p)continue;
        else if(1 & i.second)dfs(i.first,v,c^1);
        else dfs(i.first,v,c);
    }
}

signed main (){
    int n;cin>>n;
    g.resize(n);
    ans.resize(n,0);
    rep(i,0,n-1){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        g[a].pb(mp(b,c));
        g[b].pb(mp(a,c));
    }
    dfs(0,-1,0);
    rep(i,0,n)cout<<ans[i]<<nnn;
    return 0;
}
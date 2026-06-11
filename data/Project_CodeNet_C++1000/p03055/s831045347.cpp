#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}

vvi g;
vi depth;
void dfs(int i,int p){
    for(int x:g[i]){
        if(x==p)continue;
        depth[x]=depth[i]+1;
        dfs(x,i);
    }
}
int main(){
    ll n;cin>>n;
    g=vvi(n);
    depth=vi(n);
    rep(i,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    depth[0]=0;
    dfs(0,-1);
    ll k,d=0;
    rep(i,n)if(chmax(d,depth[i]))k=i;
    depth[k]=0;
    dfs(k,-1);
    rep(i,n)chmax(d,depth[i]);
    if((d+1)%3==2)cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}

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
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
bool ok=true;
V<int> d;
V<int> g[200005];
void dfs(int cur,int c){
    d[cur]=c;
    for(int v:g[cur]){
        if(d[v]==c)ok=false;
        if(d[v]==-1){
           dfs(v,c^1);
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    d.assign(n,-1);
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(0,0);
    ll cnt=0;
    for(int i=0;i<n;i++)if(d[i])cnt++;
    if(ok)cout<<cnt*(n-cnt)-m<<"\n";
    else cout<<n*(n-1)/2-m<<"\n";
}
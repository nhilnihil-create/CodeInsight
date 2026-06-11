#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct  UndirectedGraph{
   vector<vector<int>> g;
   vector<int> clr;
   vector<int> dis;
   int V;

   UndirectedGraph(int V) : V(V),
   g(vector<vector<int>>(V)),
   clr(vector<int>(V,0))
   {}
 
   //don't add (v,u) after adding (u,v)
   void add_edge(int u,int v){
       g[u].push_back(v);
       g[v].push_back(u);
   }
 
 
   //dfs for judging bipartite
   bool dfs_nib(int v,int c){
       clr[v]=c;
       for(auto x:g[v]){
           if(clr[x]==c) return false;
           if(clr[x]==0 && !dfs_nib(x,-c) ) return false;
       }
       return true;
   }
   bool isBipartite(){
       bool ret=true;
       for(int i=0;i<V;i++)if(clr[i]==0){
           if(!dfs_nib(i,1)){
               ret=false;break;
           }
       }
       return ret;
   }
 
   //distance
   void bfs(int st){
       dis=vector<int>(V,INF);
       vector<bool> checked(V,false);
       dis[st]=0;checked[st]=true;
       queue<int> q;
       q.push(st);
       while(!q.empty()){
           auto now=q.front();q.pop();
           for(auto x:g[now]){
               if(checked[x]) continue;
               checked[x]=true;
               dis[x]=dis[now]+1;
               q.push(x);
           }
       }
   }

   vector<int> color(){
       return clr;
   }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,m;cin>>n>>m;
    UndirectedGraph g(n);
    rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        g.add_edge(u,v);
    }
    if(g.isBipartite()){
        ll l=0,r=0;
        auto v=g.color();
        for(auto c:v){
            if(c==-1) l++;
            else      r++;
        }
        cout<<l*r-m<<endl;
    }else{
        cout<<n*(n-1)/2-m<<endl;
    }
    return 0;
}

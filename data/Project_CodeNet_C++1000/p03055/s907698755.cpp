#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
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
 
 
   //二部グラフ判定
   bool dfs_nib(int v,int c){
       clr[v]=c;
       for(auto x:g[v]){
           if(clr[x]==c) return false;
           if(clr[x]==0 && !dfs_nib(x,-c) ) return false;
       }
       return true;
   }
   bool isNib(){
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
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;cin>>n;
    if(n==1){
        cout<<"First"<<endl;
        return 0;
    }
    UndirectedGraph g(n);
    rep(i,n-1){
        int u,v;cin>>u>>v;u--,v--;
        g.add_edge(u,v);
    }
    g.bfs(0);
    int d=0,a=-1;
    rep(i,n){
        if(chmax(d,g.dis[i])) a=i;
    }
    g.bfs(a);
    int R=0;
    rep(i,n){
        chmax(R,g.dis[i]);
    }
    R++;
    if(R%3==2){
        cout<<"Second"<<endl;
    }
    else{
        cout<<"First"<<endl;
    }
    return 0;
}

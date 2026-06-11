#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

signed main(void){
    int n,m; cin>>n>>m;
    vector <int> to(n);
    vector <vector<int>> graph(n,vector <int>());
    vector <vector<int>> ot(n,vector <int>());
    rep(i,n+m-1){
        int a,b; cin>>a>>b;
        a--; b--;
        to[b]++;
        graph[a].push_back(b);
        ot[b].push_back(a);
    }
    priority_queue <int> que;
   
    vector <int> topo(n);
    int x = 0;
    vector <int> deg(n);
    int top;
    rep(i,n) {deg[i] = to[i]; if(to[i]==0) top = i;}
    que.push(top);
    while(!que.empty()){
        int v = que.top(); que.pop();
        topo[x++] = v;
        for(int i=0;i<graph[v].size();i++){
            int nv = graph[v][i];
            deg[nv]--;
            if(deg[nv]==0) que.push(nv);
        }
    }
    
    /*for(int i=0;i<n;i++){
        cout<<topo[i]+1<<endl;
    }*/
    vector <int> oya(n,0);
    
    rep(i,n){
        
        int now = topo[i];
        rep(j,graph[now].size()){
            oya[graph[now][j]] = now+1;
        }
    }
    rep(i,n) cout<<oya[i]<<endl;
}

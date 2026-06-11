#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int n,V;
vector<vector<int>> G(1e6);
vector<int> match(1e6,-1),used(1e6);

//uとvを結ぶ辺をグラフに追加する
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
    return;
}

bool dfs(int v){
    used[v]=true;
    rep(i,G[v].size()){
        int u=G[v][i],w=match[u];
        if(w<0||(!used[w]&&dfs(w))){
            match[v]=u;match[u]=v;
            return true;
        }
    }
    return false;
}

//2部グラフの最大マッチングを求める
int bipartite_matching(){
    int res=0;
    rep(v,n){
        if(match[v]<0){
            rep(i,200)used[i]=false;
            if(dfs(v))res++;
        }
    }
    return res;
}

int main(void){
    cin>>n;V=10000;
    vector<pair<int,int>> ps(n),pt(n);
    rep(i,n)cin>>ps[i].first>>ps[i].second;
    rep(i,n)cin>>pt[i].first>>pt[i].second;
    rep(i,n)rep(j,n){
        if(ps[i].first<pt[j].first&&ps[i].second<pt[j].second) add_edge(i,n+j);
    }
    int res=bipartite_matching();
    cout<<res<<endl;
}
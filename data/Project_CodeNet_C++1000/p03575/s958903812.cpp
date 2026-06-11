#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

struct Lowlink{
    vector<set<int>> Graph;
    vector<int> arrived,ord,low;
    int CntBri;

    Lowlink(int N, vector<set<int>> G):Graph(G){
        CntBri=0;
        arrived.assign(N,0);
        ord.assign(N,0);
        low.assign(N,0);

        Dfs(0,0,-1);
    }

    void Dfs(int node,int k,int p){
        arrived.at(node)=1;
        ord.at(node)=k;
        low.at(node)=k;

        for(auto g:Graph.at(node)){
            if(!arrived.at(g)){
                Dfs(g,k+1,node);
                low.at(node)=min(low.at(node),low.at(g));
                if(ord.at(node)<low.at(g)) CntBri++;
            }else if(g!=p){
                low.at(node)=min(low.at(node),ord.at(g));
            }
        }
    }
};

int main(){
    int N,M; cin>>N>>M;
    vector<set<int>> G(N);
    rep(m,0,M){
        int a,b; cin>>a>>b;
        G.at(a-1).insert(b-1);
        G.at(b-1).insert(a-1);
    }

    Lowlink lowlink(N,G);
    cout<<lowlink.CntBri<<endl;
}
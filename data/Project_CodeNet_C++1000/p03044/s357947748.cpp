#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

struct edge{
    int u;
    int v;
    int w;
    edge(int u,int v,int w) : u(u),v(v),w(w) {}
};


void dfs(vector<int>&,vector<vector<edge> >&,int,int);

int main()
{
    int N;cin>>N;
    vector<int> C(N,-1);
    vector<vector<edge> > L(N);
    rep(i,N-1){
        int u,v,w;
        cin>>u>>v>>w;
        L[u-1].push_back(edge(u-1,v-1,w));
        L[v-1].push_back(edge(v-1,u-1,w));
    }
    dfs(C,L,0,0);
    for(auto c : C){
        cout << c << endl;
    }

    return 0;
}

void dfs(vector<int> &C, vector<vector<edge> > &L,int u, int c)
{
    C[u] = c;
    for(auto e : L[u]){
        if(C[e.v]==-1){
            if(e.w%2==0){
                dfs(C,L,e.v,c);
            }else{
                dfs(C,L,e.v,1-c);
            }
        }
    }
}
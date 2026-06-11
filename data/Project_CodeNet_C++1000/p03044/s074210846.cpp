#include<iostream>
#include<vector>

using namespace std;

typedef int weight;

class Edge {
    public:
        int s_,t_;
        weight w_;
        Edge(int s, int t, weight w):s_(s), t_(t), w_(w) {}
};

class Graph {
    public:
        vector<vector<Edge>> edge_;
        Graph(int N) {
            edge_.resize(N);
        }
        void addEdge(int s, int t, weight w) {
            edge_[s].push_back(Edge(s, t, w));
        }
};

void dfs(int now, int prev, int color, vector<int> &colorbox, Graph &g) {
    colorbox[now] = color;
    vector<Edge> &es = g.edge_[now];
    for (int i=0;i<(int)es.size();i++) {
        if (es[i].t_ == prev) continue;
        int w = es[i].w_;
        if (w%2) {
            dfs(es[i].t_, now, color^1, colorbox, g);
        } else {
            dfs(es[i].t_, now, color, colorbox, g);
        }
    }
    return;
}

int main(){
    int N;cin>>N;
    vector<int> ans(N);
    Graph g(N);
    for (int i=1;i<N;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        u--,v--;
        g.addEdge(u,v,w);
        g.addEdge(v,u,w);
    }
    dfs(0,-1,0,ans,g);
    for (int i=0;i<N;i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
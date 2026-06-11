// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<Edge>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

struct Edge{
    int v, w;
    Edge(){}
    Edge(int v0, int w0){
        v = v0;
        w = w0;
    }
};

int main(){
    int N;
    cin >> N;
    Graph G(N);
    rep(i, N - 1){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        w %= 2;

        Edge e(v, w);
        G[u].push_back(e);

        e.v = u;
        G[v].push_back(e);
    }

    vector<int> color(N, -1);
    queue<int> que;
    que.push(0);
    color[0] = 0;

    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(Edge e : G[u]){
            if(color[e.v] != -1) continue;
            color[e.v] = (color[u] + e.w) % 2;
            que.push(e.v);
        }
    }

    for(int i : color){
        cout << i << endl;
    }
}
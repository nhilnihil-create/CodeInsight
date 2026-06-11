#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<int,Int> p;

Int N, M; 
vector<vector<p>> graph(100010);
vector<Int> dist(100010, 1e10);

bool bfs(int id){
    queue<int> Q;
    Q.push(id); dist[id] = 0;

    while(!Q.empty()){
        int v = Q.front(); Q.pop();

        for(p edge : graph[v]){
            int u = edge.first; Int d = edge.second;

            if(dist[u] == 1e10){
                dist[u] = dist[v] + d;
                Q.push(u);
            } else if (dist[u] != dist[v] + d){
                return false;
            }
        }
    }

    return true;
}




int main(){
    cin >> N >> M;
    rep(i,M){
        int L,R; Int D; cin >> L >> R >> D;
        graph[L-1].push_back(p(R-1,D));
        graph[R-1].push_back(p(L-1,-D));
    }

    rep(i,N){
        if(dist[i] == 1e10){ 
            if(!bfs(i)){
                cout << "No" << endl;
                return 0;
            }
        }
        
    }

    cout << "Yes" << endl;
}
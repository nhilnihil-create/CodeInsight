#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> P;

int dist[100001];
vector<P> edge[100001];

bool dfs(int n, int d){
    dist[n] = d;
    for(int i = 0; i < edge[n].size(); i++){
        if(dist[edge[n][i].first] != INT32_MIN && dist[edge[n][i].first] != dist[n] + edge[n][i].second) return false;
        if(dist[edge[n][i].first] == INT32_MIN){
            if(dfs(edge[n][i].first, dist[n] + edge[n][i].second) == false) return false;
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        dist[i] = INT32_MIN;
    }
    for(int i = 0; i < M; i++){
        int L, R, D;
        cin >> L >> R >> D;
        edge[L].push_back(P(R, D));
        edge[R].push_back(P(L, -D));
    }
    for(int i = 1; i <= N; i++){
        if(dist[i] == INT32_MIN){
            if(dfs(i, 0) == false){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
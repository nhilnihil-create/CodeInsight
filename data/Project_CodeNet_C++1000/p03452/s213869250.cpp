#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int> > graph[100010];
bool visited[100010] = {};
int dist[100010];
int n, m;

bool dfs(int i, int cost){
    if(visited[i]){
        return dist[i] == cost;
    }

    visited[i] = true;
    dist[i] = cost;

    for(int j = 0;j < graph[i].size();j++){
        if(!dfs(graph[i][j].first, cost + graph[i][j].second)){
            return false;
        }
    }

    return true;
}

signed main(){
    cin >> n >> m;

    int l, r, d;
    for(int i = 0;i < m;i++){
        cin >> l >> r >> d;
        l--;
        r--;
        graph[l].push_back(make_pair(r, d));
        graph[r].push_back(make_pair(l, -d));
    }

    for(int i = 0;i < n;i++){
        if(!visited[i]){
            if(!dfs(i, 0)){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}

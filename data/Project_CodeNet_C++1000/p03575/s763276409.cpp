#include <iostream>
#include <vector>
using namespace std;
using P = pair<int, int>;

void dfs(vector<vector<int>>& G, vector<bool>& isvisit, int start, P excludeEdge){
    if(isvisit[start]) return;
    else isvisit[start] = true;
    for(int i = 0; i < G[start].size(); i++){
        if((start == excludeEdge.first && G[start][i] == excludeEdge.second) ||
        (start == excludeEdge.second && G[start][i] == excludeEdge.first)) continue;
        dfs(G, isvisit, G[start][i], excludeEdge);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> E(m);
    vector<vector<int>> G(n+1);
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        E[i] = make_pair(s, t);
        G[s].push_back(t);
        G[t].push_back(s);
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        vector<bool> isvisit(n+1, false);
        dfs(G, isvisit, 2, E[i]);
        bool islinking = true;
        for(int i = 1; i <= n; i++){
            if(!isvisit[i]) islinking = false;
        }
        if(!islinking) ans++;
    }
    cout << ans << endl;
    return 0;
}
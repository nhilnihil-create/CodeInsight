#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> indeg;

int main(void){
    int N, M; cin >> N >> M;
    G.resize(N);
    indeg.resize(N);
    for (int i = 0; i < N+M-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        indeg[b] += 1;
    }
    
    
    vector<int> ans(N); 
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) {
            ans[i] = -1;
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int q_top = q.front();
        q.pop();
        
        for (int i = 0; i < G[q_top].size(); i++) {
            int to = G[q_top][i];
            indeg[to] -= 1;
            if (indeg[to] == 0) {
                ans[to] = q_top;
                q.push(to);
            }
        }
    }
    
    for (auto i : ans) {
        cout << i+1 << endl;
    }
}

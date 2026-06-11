#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    vector<P> edges[n];
    
    rep(i, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        /*
        edges[u].push_back(make_pair(v, w))
        edges[v].push_back(make_pair(u, w))
        */
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    };
    
    vector<bool> visited(n, false);
    vector<int> colors(n, -1);
    stack<int> stk;
    stk.emplace(0);
    while (stk.size() != 0){   
        int p = stk.top();
        stk.pop();
        for (P c : edges[p]){
            if(visited[c.first]) continue;
            visited[c.first] = true;
            stk.push(c.first);
            if (c.second % 2 == 0)
                colors[c.first] = colors[p];
            else colors[c.first] = (-1)*colors[p];
        }
    }
        
    rep(i, n){
        if (colors[i] == -1) cout << 0 << endl;
        else cout << 1 << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > G;

int main(){

    int n, m;
    cin >> n >> m;
    G.resize(n);
    vector<int> deg(n, 0);
    vector<int> a(n-1+m), b(n-1+m);
    for(int i = 0; i < n-1+m; ++i) {
        cin >> a[i] >> b[i]; --a[i]; --b[i];
        G[a[i]].push_back(b[i]);
        ++deg[b[i]];
    }
    vector<int> d(n, 0);
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto e : G[x]) {
            --deg[e];
            d[e] = max(d[e], d[x]+1);
            if(deg[e] == 0) q.push(e);
        }
    }

    vector<int> parent(n, 0);
    for(int i = 0; i < n-1+m; ++i) {
        if(d[b[i]] == d[a[i]]+1) parent[b[i]] = a[i]+1;
    }
    for(auto x : parent) cout << x << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

void dfs(int cur, int par, vector<int>& d){
    for(int nex : g[cur]){
        if(nex == par) continue;
        d[nex] = d[cur] + 1;
        dfs(nex, cur, d);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    g.resize(n);

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<long long> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    vector<int> d1(n, 0);
    dfs(0, -1, d1);

    int node = 0;
    for(int i = 0; i < n; i++){
        if(d1[node] < d1[i]) node = i;
    }

    vector<int> d2(n, 0);
    dfs(node, -1, d2);

    int node2 = 0;
    for(int i = 0; i < n; i++){
        if(d2[node2] < d2[i]) node2 = i;
    }
    int max_val = d2[node2];

    vector<int> d3(n, 0);
    dfs(node2, -1, d3);

    vector<int> d(n), ord(n);
    for(int i = 0; i < n; i++){
        d[i] = min({d2[i], d3[i], max_val - d2[i], max_val - d3[i]});
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](const int i1, const int i2){return d[i1] < d[i2];});

    vector<int> used(n, false);
    long long ans = 0;
    vector<int> memo(n, 0);
    for(int ii = 0; ii < n; ii++){
        int i = ord[ii];
        memo[i] = c[ii];
        for(int j : g[i]){
            if(used[j]) continue;
            ans += c[ii];
        }
        used[i] = true;
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << memo[i] << " \n"[i+1 == n];
    }
    return 0;
}
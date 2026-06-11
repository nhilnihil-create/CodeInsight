#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

using Graph = vector<vector<int>>;

void dfs(int prev, int u, int d, vector<pair<int, int>> &v, const Graph &tree){
    v[u-1].first = d;
    for(auto to: tree[u]){
        if(to == prev)continue;
        dfs(u, to, d+1, v, tree);
    }
}

int main(){
    int n;
    cin >> n;
    Graph tree(n+1, vector<int>());
    for(int i=0;i<n-1;++i){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> c(n);
    for(int i=0;i<n;++i){
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    vector<pair<int, int>> v(n);
    for(int i=0;i<n;++i)v[i].second = i+1;
    dfs(0, 1, 0, v, tree);
    sort(v.rbegin(), v.rend());

    vector<int> ans(n+1);
    for(int i=0;i<n;++i){
        ans[v[i].second] = c[i];
    }

    int m = 0;
    for(int i=1;i<=n;++i){
        for(auto to: tree[i]){
            m += min(ans[i], ans[to]);
        }
    }

    cout << m / 2 << endl;
    for(int i=0;i<n;++i){
        if(i)cout << " ";
        cout << ans[i+1];
    }
    cout << endl;

    return 0;
}
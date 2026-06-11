#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
vector<vector<int>> v; vector<int> in;
bool f = 0;
vector<int> to_sort(vector<vector<int>>& G, vector<int>& ind, int V) {
    vector<int> sorted(V); queue<int> q;
    rep(i, V) {
        if (ind[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i : G[v]) {
            ind[i]--;
            if (ind[i] == 0)sorted[i] = v+1,q.push(i);
        }
    }return sorted;
}
int main() {
    int n, m, x, y; cin >> n >> m;
    v.resize(n+m+1); in.resize(n+m+1, 0);
    rep(i, n+m-1) {
        cin >> x >> y; x--; y--;
        v[x].push_back(y);
        in[y]++;
    }vector<int> ans = to_sort(v, in, n+m-1);
    rep(i, n) cout << ans[i] << endl;
}
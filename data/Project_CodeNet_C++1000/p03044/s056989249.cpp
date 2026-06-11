#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<vector<pair<int,int>>> hen;
vector<int> col;

void dfs(int v, int par) {
    for(auto i : hen[v]) {
        if(i.first == par)continue;
        col[i.first] = (i.second % 2 ? !col[v] : col[v]);
        dfs(i.first, v);
    }
}

int main()
{
    cin >> n;
    hen.resize(n), col.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        hen[a].emplace_back(b, c);
        hen[b].emplace_back(a, c);
    }

    dfs(0, -1);
    for(auto i : col)cout << i << endl;
}
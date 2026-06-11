#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> to, ot;
vector<bool> seen_par;
vector<int> ans;



void dfs(int v, int par) {
    for(auto i : ot[v])if(seen_par[i])return; //次の世代の子供ではない

    ans[v] = par;
    seen_par[v] = false;

    for(auto i : to[v]) {
        dfs(i, v);
    }

    seen_par[v] = true;
}

int main()
{
    cin >> n >> m;
    to.resize(n), ot.resize(n), seen_par.resize(n, true), ans.resize(n);

    for(int i = 0; i < m + n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        to[a].push_back(b);
        ot[b].push_back(a);
    }


    for(int i = 0; i < n; i++) {
        dfs(i, -1);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] + 1 << endl;
    }

}
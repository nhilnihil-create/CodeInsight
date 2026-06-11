#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> c;
int cnt;

void dfs(int cur, int par, vector<int>& d){
    d[cur] = c[cnt++];
    for(int nex : g[cur]){
        if(nex == par) continue;
        dfs(nex, cur, d);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    g.resize(n);
    c.resize(n);

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long sum = 0;
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        sum += c[i];
        mx = max(mx, c[i]);
    }
    sort(c.rbegin(), c.rend());

    cnt = 0;
    vector<int> d1(n, 0);
    dfs(0, -1, d1);

    long long ans = sum - mx;
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << d1[i] << " \n"[i+1 == n];
    }
    return 0;
}
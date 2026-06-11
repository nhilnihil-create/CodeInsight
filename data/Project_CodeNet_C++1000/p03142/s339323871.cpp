#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<int> G[100010];
vector<int> l;

void dfs(vector<bool>& used, int i) {
    used[i] = true;
    for (int j : G[i]) if (!used[j]) dfs(used,j);
    l.push_back(i);
}

int main() {
    int n,m,par;
    cin >> n >> m;
    vector<bool> used(n,false),child(n,false);
    vector<int> a(n),ans(n,n);
    for (int i = 0;i < n+m-1;++i) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        child[v] = true;
    }
    for (int i = 0;i < n;++i) if (!child[i]) par = i;
    dfs(used,par);
    a.push_back(n);
    for (int i = 0;i < n;++i) a[l[i]] = i;
    for (int i = 0;i < n;++i) for (int& j : G[i]) if (a[ans[j]] > a[i]) ans[j] = i;
    for (int i = 0;i < n;++i) cout << (ans[i]+1)%(n+1) << "\n";
    return 0;
}
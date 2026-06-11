#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 200005;
const int K = 50;
set < int > g1[N], g2[N];
int f[N], invf[N], s[N], dp[N], used[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        if (s[u - 1] == 'A') g1[v].insert(u); else g2[v].insert(u);
        if (s[v - 1] == 'A') g1[u].insert(v); else g2[u].insert(v);
    }
    set < int > t;
    for (int i = 1; i <= n; i++){
        if (g1[i].size() == 0 || g2[i].size() == 0){
            t.insert(i);
            used[i] = 1;
        }
    }
    while(!t.empty()){
        int v = *t.begin();
        t.erase(t.begin());
        for (auto u: g1[v]){
            if (u == v) continue;
            g1[u].erase(v);
            g2[u].erase(v);
            if (g1[u].size() == 0 || g2[u].size() == 0 && !used[u]){
                t.insert(u);
                used[u] = 1;
            }
        }
        for (auto u: g2[v]){
            if (u == v) continue;
            g1[u].erase(v);
            g2[u].erase(v);
            if (g1[u].size() == 0 ||  g2[u].size() == 0 && !used[u]){
                t.insert(u);
                used[u] = 1;
            }
        }
        while(!g1[v].empty()) g1[v].erase(g1[v].begin());
        while(!g2[v].empty()) g2[v].erase(g2[v].begin());
    }
    for (int i = 1; i <= n; i++){
        if (g1[i].size() != 0 && g2[i].size() != 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No";
}

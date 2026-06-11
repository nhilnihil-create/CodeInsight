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
const int mod = 998244353;
const int N = 10000005;
const int K = 25;
int d[N], sz[N], p[N], f[N];
pair < int, int > a[N];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
        a[i] = {d[i], i};
    }
    set < pair < int, int > > s;
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = 1; i <= n; i++){
        int v = a[i].S;
        auto x = s.lower_bound({d[v], 0});
        while(x != s.end() && (*x).F == d[v]){
            int u = (*x).S;
            p[u] = v;
            f[v] += f[u] + sz[u];
            sz[v] += sz[u];
            x++;
        }
        s.insert({d[v] + sz[v] - (n - sz[v]), v});
    }
    vector < pair < int, int > > ans;
    for (int i = 1; i <= n; i++){
        if (p[i] != 0){
            ans.pb({i, p[i]});
        } else if (f[i] != d[i]){
            cout << -1;
            return 0;
        }
    }
    if (ans.size() != n - 1) cout << -1; else{
        for (auto i: ans){
            cout << i.F << " " << i.S << endl;
        }
    }
}

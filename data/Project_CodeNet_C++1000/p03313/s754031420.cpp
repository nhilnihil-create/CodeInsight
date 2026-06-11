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
const int N = 2000000;
set < int > ms;
int used[N], t[N], color[N], r[N], cv, v[N], s[N], u[N], n, m, val[N];
pair < int, int > p[N];
vector < pair < int, int > > g[N];
pair < int, int > ans[N];
int res[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++){
        cin >> ans[i].F;
    }
    for (int j = 0; j < n; j++){
        for (int i = 0; i < (1 << n); i++){
            if (!((1 << j) & i)){
                int x = ans[i | (1 << j)].F;
                int y = ans[i | (1 << j)].S;
                int t = ans[i].F;
                int z = ans[i].S;
                multiset < int > s;
                s.insert(-x);
                s.insert(-y);
                s.insert(-t);
                s.insert(-z);
                auto it = s.begin();
                ans[i | (1 << j)].F = -(*it);
                it++;
                ans[i | (1 << j)].S = -(*it);
            }
        }
    }
    for (int i = 1; i < (1 << n); i++){
        res[i] = max(ans[i].F + ans[i].S, res[i - 1]);
        cout << res[i] << endl;

    }
}

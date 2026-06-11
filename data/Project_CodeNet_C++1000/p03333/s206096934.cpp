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
int n, s;
vector < int > ans;
vector < int > g[N], b[2];
set < int > h[N];
int a[N], p[N], dep[N], l[N], r[N], color[N];
int solve(){
    set < pair < int, int > > le;
    set < pair < int, int > > re;
    for (int i = 1; i <= n; i++){
        le.insert({-l[i], i});
        re.insert({r[i], i});
    }
    int res = 0;
    int p = 0;
    int c = 1;
    while(1){
     //   cout << p << endl;
        if (c == 1){
            if (le.size() == 0) return res + abs(p);
            int x = -(*le.begin()).F;
            int in = (*le.begin()).S;
          //  cout << x << endl;
            if (x <= p) return res + abs(p);
            res += abs(p - x);
            p = x;
            le.erase(le.begin());
            re.erase({r[in], in});
            c = 0;
        } else{
            if (re.size() == 0) return res + abs(p);
            int x = (*re.begin()).F;
            int in =(*re.begin()).S;
            if (x >= p) return res + abs(p);
            res += abs(p - x);
            p = x;
            re.erase(re.begin());
            le.erase({-l[in], in});
            c = 1;
        }
    }
    cout << endl;
    return res + abs(p);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  //  freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    int ans = solve();
    for (int i = 1; i <= n; i++){
        r[i] = -r[i];
        l[i] = -l[i];
        swap(l[i], r[i]);
    }
    ans = max(ans, solve());
    cout << ans;
}

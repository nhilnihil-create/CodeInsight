#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
//#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 3000000;
int mod = 1e9 + 7;
int f[N], dp[N], s[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int c = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) if (s[i] == 'x') c++;
    if (c >= 8){
        cout << "NO";
    } else cout << "YES";
}

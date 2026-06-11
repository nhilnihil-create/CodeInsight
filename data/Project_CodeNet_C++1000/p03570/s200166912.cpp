#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define ll long long
#define ull  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 201000;
int f[1 << 26];
int a[N], dp[N];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt",  "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    set < pair < int, int > > ss;
    int n = s.length();
    for (int i = 1; i <= n; i++){
        int k = s[i - 1] - 'a';
        a[i] = ((a[i - 1]) ^(1 << k));
        for (int j = 0; j < 26; j++){
            f[(a[i] ^ (1 << j))] = 1e9;
        }
    }
    dp[0] = 1;
    f[0] = 0;
    for (int i = 1; i <= n; i++){
        int x = f[a[i]];
        for (int j = 0; j < 26; j++){
            x = min(f[(a[i] ^ (1 << j))], x);
        }
        x++;
        f[a[i]] = min(f[a[i]], x);
        dp[i] = x;
    }
    cout << dp[n];
}

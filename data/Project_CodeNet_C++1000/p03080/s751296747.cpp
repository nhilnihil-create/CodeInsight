#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 35000;
const int K = 19;
int mod =  998244353;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'R') r++;
    int b = n - r;
    if (r > b) cout << "Yes"; else cout << "No";
}

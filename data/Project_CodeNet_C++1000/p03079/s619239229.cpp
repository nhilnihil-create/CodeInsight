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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && c == a) cout << "Yes"; else cout << "No";
}

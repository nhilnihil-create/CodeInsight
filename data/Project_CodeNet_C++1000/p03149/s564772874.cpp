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
const int N = 300000;
const int K = 19;
int a[N];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9){
        cout << "YES";
        return 0;
    }
    cout << "NO";

}

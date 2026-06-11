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
const int N = 2000005;
const int K = 50;
set < int > g1[N], g2[N];
int s1[N], s2[N], a[N], b[N], x[N];
bool snuke(int x){
    int s = 0;
    int z = x;
    int p = 1;
    int f = 1;
    while(z){
        s += z % 10;
        if (z % 10 == 9 && f) p = 10 * p;
        if (z % 10 != 9) f = 0;
        z /= 10;
    }
    if (x <= p * s) return 1;
    return 0;

}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int k;
    cin >> k;
    set < int > sn;
    int p = 1;
    int d = 0;
    for (int i = 0; i < 15; i++){
        for (int j = 1; j <= 999; j++){
            sn.insert(j * p + d);
           // cout << j * p + d << endl;
        }
        p = p * 10;
        d = 10 * d + 9;
    }
    while(k){
        if (snuke(*sn.begin())){
            k--;
            cout << *sn.begin() << endl;
        }
        sn.erase(sn.begin());
    }
}

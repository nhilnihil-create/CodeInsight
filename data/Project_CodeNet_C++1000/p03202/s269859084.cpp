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
const int N = (1 << 20);
const int K = 300000;
int a[N], n;
map < int, int > m;
int ok(int x){
    m.clear();
    for (int i = 2; i <= n; i++){
        if (a[i] > a[i - 1]) continue;
        int p = a[i];
        while(1){
            if (m[p] < x - 1){
                m[p]++;
                auto it = m.upper_bound(p);
                vector < pair < int, int > > v;
                while(it != m.end()){
                    v.pb(*it);
                    it++;
                }
                for (auto j: v) m.erase(j.F);
                break;
            } else{
                m.erase(p);
                p--;
            }
            if (p <= 0){
                return 0;
            }
        }
    }
    return 1;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int f = 1;
    for (int i = 2; i <= n; i++){
        if (a[i] <= a[i - 1]) f = 0;
    }
    if (f){
        cout << 1;
        return 0;
    }
    int l = 1;
    int r = n;
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (ok(mid)) r = mid; else l = mid;
    }
    cout << r;
}

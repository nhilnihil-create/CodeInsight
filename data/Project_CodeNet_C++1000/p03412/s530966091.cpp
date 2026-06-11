#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using order_statistics_tree = tree<T,null_type,less_equal<T>,rb_tree_tag,
  tree_order_statistics_node_update>;
 #define all(x) (x).begin(),(x).end()
vector<int> u, v, dest;
inline void trunc(vector<int>& vec, int t){
   auto it = upper_bound(all(vec), t);
   for(auto&j: vec)j&=t;
   merge(vec.begin(), it, it, vec.end(), dest.begin());
   copy(all(dest), vec.begin());
}
signed main(){
    int n;
    cin >> n;
    u.resize(n); v.resize(n); dest.resize(n);
    for(auto& i: u) cin >> i;
    for(auto& i: v) cin >> i;
    int ans = 0;
    if(n&1){
        for(auto j: v)ans^=j;
        for(auto j: u)ans^=j;
    }
    sort(all(v));
    sort(all(u));
    for(int i = 28, t = (1<<29)-1; i >= 0; i--, t>>=1){
        trunc(v, t);
        trunc(u, t);
        for(int ui = 0, vi = n; ui< n; ui++){
            while(vi>0 && u[ui]+v[vi-1] > t)vi--;
            ans^=((n-vi)&1)<<i+1;
        }
    }
    cout << ans <<endl;
}

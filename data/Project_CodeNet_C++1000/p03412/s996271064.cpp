#include<iostream>
#include<vector>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using order_statistics_tree = tree<T,null_type,less_equal<T>,rb_tree_tag,
  tree_order_statistics_node_update>;
vector<int> u, v, ost;
signed main(){
    int n;
    cin >> n;
    u.resize(n); v.resize(n);
    for(auto& i: u) cin >> i;
    for(auto& i: v) cin >> i;
    int ans = 0;
    if(n&1){
        for(auto j: v)ans^=j;
        for(auto j: u)ans^=j;
    }
    for(int i = 28, t = (1<<29)-1; i >=0; i--, t>>=1){
        for(auto&j: v)j&=t;
        sort(v.begin(),v.end());
        int cnt = 0;
        for(auto j: u)cnt^=v.end()-upper_bound(v.begin(),v.end(), t^j&t);
        ans^=(cnt&1)<<i+1;
    }
    cout << ans <<endl;
}

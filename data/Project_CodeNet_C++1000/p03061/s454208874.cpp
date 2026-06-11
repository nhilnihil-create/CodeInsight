//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
    int n;
    cin >> n;
    int a[n+2];
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int left[n+2]={0}, right[n+2]={0};
    int gc = 0;
    for(int i=1; i<=n; i++){
        gc = __gcd(a[i], gc);
        left[i] = gc;
    }
    gc = 0;
    for(int i=n; i>0; i--){
        gc = __gcd(gc, a[i]);
        right[i] = gc;
    }
    int mx = 0;
    for(int i=1; i<=n; i++){
        mx = max(mx, __gcd(left[i-1], right[i+1]));
    }
    cout << mx << '\n';

    return 0;
}

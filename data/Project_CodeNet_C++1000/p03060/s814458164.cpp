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
    vector<lli> v, c;
    for(int i=0; i<n; i++){
        lli x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i<n; i++){
        lli x;
        cin >> x;
        c.push_back(x);
    }
    lli mx = -1e9;
    for(int i=0; i<(1<<n); i++){
        lli x = 0, y=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                x+=v[j];
                y+=c[j];
            }
        }
        mx = max(mx, x-y);
    }
    cout << mx << endl;

    return 0;
}

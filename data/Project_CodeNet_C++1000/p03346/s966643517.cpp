#include <bits/stdc++.h>
#include <string>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define pii pair<int, int>
//#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define jai_shree_ram  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i, a, b, d) for (int i = a; i <= b; i += d)
#define brep(i, a, b, d) for (int i = a; i >= b; i -= d)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int MOD = 1e9 + 7;
////////////////////////////////


int32_t main(){
    jai_shree_ram
    int n;
    cin >> n;
    int a[n+1];
    rep(i,1,n,1) cin >> a[i];
    int ans = 0;
    map <int, int> m;
    rep(i,1,n,1){
        if(!m[a[i]-1]) m[a[i]] = 1;
        else m[a[i]] = m[a[i]-1] + 1;
        ans = max(ans, m[a[i]]);
    }
    cout << n - ans << endl;
    return 0; 
}

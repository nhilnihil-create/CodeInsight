#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
using namespace std;
// using cd = complex<double>;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;
 
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
typedef long long int ll;
typedef long double ld;
const ll N = 1e6;
// const ll m = 1e9 + 7;
const ll inf= 1e14;
const ll mod =1e9+7;
const double PI = acos(-1);
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define pld pair<ld,ld>
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
ll n;
ll a[N];
ll f(ll b){
    ll ans =0;
    for(int i = 0;i<n;i++){
        ans+=abs(a[i]-b);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr); 
    #endif  
    ll t = 1;
    // cin>>t;
    while(t--){
        cin>>n;
        ll ma = 0,mi = inf;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            a[i]-=(i+1);
            ma = max(ma,a[i]);
            mi = min(mi,a[i]);
        
        }
        ll B = ma,A = mi;
        while(B - A > 4)
        {
            int m1 = (A + B) / 2;
            int m2 = (A + B) / 2 + 1;

            if(f(m1) > f(m2))
               A = m1;
            else
               B = m2;
        }

        ll ans = inf;
        // cout<<ans<<'\n';

        for(int i = A; i <= B; i++){
            ans = min(ans , f(i));
        }
        cout<<ans<<'\n';
    }
        
}
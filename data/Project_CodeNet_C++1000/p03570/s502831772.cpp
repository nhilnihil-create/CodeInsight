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
void pr(ll x){
    bitset<26> a = x;
    cout<<a<<" "<<x<<'\n';
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

        string s;cin>>s;
        map<ll,ll> dp;
        ll n = s.size();
        ll ct[26],dp1[n];
        memset(ct,0,sizeof(ct));

        for(int i = 0;i<n;i++){

            dp1[i] = inf;
            ct[s[i]-'a']++;
            ll thi = 0;
            ll no_on = 0;
            for(int i = 0;i<26;i++){
                thi+=(ct[i]%2)<<i;
                no_on+=(ct[i]%2);
            }

            // pr(thi);
            if(no_on<2){
                dp[thi] = 1;
                dp1[i] = 1;
            }
            else{
                if(dp[thi]!=0){
                    dp1[i] = dp[thi]+1;
                }

                for(int j = 0;j<26;j++){
                    ll nv = thi^(1ll<<j);
                    // pr(nv);
                    // cout<<dp[nv]<<" "<<dp1[i]<<" ";
                    if(dp[nv]!=0){
                        dp1[i]=min(dp1[i],dp[nv]+1);
                    }
                    // cout<<dp1[i]<<'\n';
                }
            }
            if(dp[thi]==0){
                dp[thi] = dp1[i];
            }
            dp[thi] = min(dp[thi],dp1[i]);

            // cout<<'\n';

        }
        cout<<dp1[n-1]<<'\n';
    }
        
}
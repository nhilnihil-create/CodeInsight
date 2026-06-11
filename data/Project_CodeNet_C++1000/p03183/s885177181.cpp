#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long,long long> ii; 	
typedef complex<long double> com;

const ll mod = 1e9+7;

struct brick{
    ll w,s,v;
    bool operator<(const brick& rhs) const{
        return s+w < rhs.s+rhs.w;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n;
    cin >> n;
    vector <brick> arr(n);
    ll maxi = 0;
    for (int z=0;z<n;z++){
        cin >> arr[z].w >> arr[z].s >> arr[z].v;
        maxi = max(maxi,max(arr[z].w,arr[z].s));
    }
    sort(arr.rbegin(),arr.rend());
    vector <vector<ll>> dp(n,vector<ll>(maxi+1,0));
    dp[0][arr[0].s] = arr[0].v;
    for (int z=1;z<n;z++){
        dp[z][arr[z].s] = arr[z].v;
        for (int x=0;x<=maxi;x++){
            dp[z][x] = max(dp[z-1][x],dp[z][x]);
            if (dp[z][x] == 0) continue;
            if (x >= arr[z].w) 
            dp[z][min(x-arr[z].w,arr[z].s)] = max(dp[z][min(x-arr[z].w,arr[z].s)],dp[z-1][x]+arr[z].v);
        }
    }
    // for (int z=0;z<n;z++){
    //     for (int x=0;x<=maxi;x++){
    //         cout << dp[z][x] << " ";
    //     } cout << endl;
    // }
    ll ans = 0;
    for (int z=0;z<=maxi;z++){
        ans = max(ans,dp[n-1][z]);
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define oset tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> 
//order_of_key (k) : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    vector<ll> dp(n);
    dp[0]=0; dp[1]=abs(a[0]-a[1]);
    for(ll i=2;i<n;i++)
        dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]), dp[i-2]+abs(a[i]-a[i-2]));
    cout<<dp[n-1];


    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}
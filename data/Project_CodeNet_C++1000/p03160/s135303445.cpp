#include<bits/stdc++.h> 
using namespace std;
#define rush             ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll               long long int
#define FOR(a,x,n)       for(ll a=x;a<n;a++)
#define ROF(a,x,n)       for(ll a=x;a>=n;a--)
#define pb               push_back
#define lb               lower_bound
#define ub               upper_bound
#define MOD              1000000007

ll dp[100005];

ll ans(ll a[], ll n, ll index) {
       if(index == n-1) return 0;

       if(dp[index] != -1) return dp[index];
       
       ll left = abs(a[index] - a[index+1]) + ans(a, n, index+1);
       ll right = INT_MAX;

       if(index+2 < n) right = abs(a[index] - a[index+2]) + ans(a, n, index+2);

       return dp[index] = min(left, right);  
}

void solve() {
     ll n;
     cin >> n;

     memset(dp, -1, sizeof dp);

     ll a[n];
     FOR(i,0,n) cin >> a[i];

     cout << ans(a, n, 0);
}
 
int main() {
        rush
        solve();
}
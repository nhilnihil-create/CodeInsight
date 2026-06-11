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

ll a[100005];
ll dp[100005];

ll n, k;

ll ans(ll index) {
       if(index == n-1) return 0;

       ll minn = LLONG_MAX;

       if(dp[index] != -1) return dp[index];
       
       for(ll i=index+1; i<=min(n-1, index+k); i++) {
           minn = min(minn, min(minn, abs(a[i] - a[index])) + ans(i)); 
       }

       return dp[index] = minn;  
}

void solve() {
     cin >> n >> k;

     memset(dp, -1, sizeof dp);

     FOR(i,0,n) cin >> a[i];

     cout << ans(0);
}
 
int main() {
        rush
        solve();
}
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

ll a[100005][3];
ll ans[100005][3];

void solve() {
     ll n;
     cin >> n; 

     FOR(i,0,n) {
         FOR(j,0,3) {
             cin >> a[i][j];    
         }    
     }

     ans[0][0] = a[0][0];
     ans[0][1] = a[0][1];
     ans[0][2] = a[0][2];

     FOR(i,1,n) {
         ans[i][0] = a[i][0] + max(ans[i-1][1], ans[i-1][2]);
         ans[i][1] = a[i][1] + max(ans[i-1][0], ans[i-1][2]);
         ans[i][2] = a[i][2] + max(ans[i-1][0], ans[i-1][1]);    
     }

     cout << max(ans[n-1][0], max(ans[n-1][1], ans[n-1][2]));
}
 
int main() {
        rush
        solve();
}
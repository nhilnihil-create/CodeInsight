#include<bits/stdc++.h>
#define ll  long long int
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define pii pair<ll,ll>
#define ve vector
#define piii pair<pii, ll>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

ll a[25][25], mod=1e9+7;
ll dp[25][5000000];

ll ways(ll ind, ll n, ll visited){
    if( ind >= n )
      return 1;
    if( dp[ind][visited] != -1)
      return dp[ind][visited];

    ll ans = 0;
    for(int i=0; i<n; i++){
        if( ((visited>>i)&1) == 0 && a[ind][i] == 1){
          visited |= (1<<i);
          ans += ways(ind+1, n, visited );
          ans %= mod;
          visited ^= (1<<i);
        }
    }
    dp[ind][visited] = ans;
    return ans;
}
int main(){
   
   for(int i=0; i<25; i++){
      for(int j=0; j<5000000; j++){
          dp[i][j] = -1;
      }
   }
   ll n;
   cin>>n;

   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>>a[i][j];
      }
   }

   ll ans = ways(0, n, 0);
   cout<<ans<<endl;
} 
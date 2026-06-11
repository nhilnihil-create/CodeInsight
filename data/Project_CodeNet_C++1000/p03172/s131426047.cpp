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

ll mod = 1e9+7;
ll dp[110][100010];
ll sum[100010];
vector<ll> v;

int main(){
   
   ll n,x,k;
   cin>>n>>k;

   v.push_back(0);
   for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
   }
   
   for(int i=1; i<=k; i++)
      dp[0][i] = 0;
   dp[0][0] = 1;

   for(int i=1; i<=n; i++){
      for(int j=1; j<=k; j++){
          dp[i-1][j] += dp[i-1][j-1];
          dp[i-1][j] %= mod;
      }
      for(int j=0; j<=k; j++){
          dp[i][j] = dp[i-1][j];
          dp[i][j] -= ( j-v[i]-1 >= 0 )?dp[i-1][j-v[i]-1]:0;
          dp[i][j] += mod;
          dp[i][j] %= mod;
      }
      // for(int j=0; j<=k; j++){
      //     cout<<dp[i][j]<<" ";
      // }
      // cout<<endl;
   }

   cout<<dp[n][k]<<endl;

}
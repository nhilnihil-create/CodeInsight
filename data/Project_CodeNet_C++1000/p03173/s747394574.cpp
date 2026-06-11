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


int main(){
   
   ll n,x,k;
   cin>>n;
   ll cost[n][n], siz[n][n];

   for(int i=0; i<n; i++)
     cin>>siz[i][i];

   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cost[i][j] = 1e16;
      }
      cost[i][i] = 0;
   }

   for(int l=1; l<=n; l++){
      for(int i=0, j=l-1; i<n && j<n; i++,j++){
          for(int k=i; k<j; k++){
            ll c =  cost[i][k]+cost[k+1][j]+siz[i][k]+siz[k+1][j];
            if( c < cost[i][j] )
                cost[i][j] = c, siz[i][j] = siz[i][k]+siz[k+1][j];
            else if( c == cost[i][j] && siz[i][j] > siz[i][k]+siz[k+1][j]  )
                cost[i][j] = c, siz[i][j] = siz[i][k]+siz[k+1][j];
          }
      }
   }

   cout<<cost[0][n-1];

} 
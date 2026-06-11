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

vector<int> v[100010];
ll black[100010], white[100010], mod=1e9+7;

void dfs(ll x, ll p){
    for( auto y: v[x] ){
        if( y == p )
          continue;
        dfs( y, x);
        white[x] *= (white[y]+black[y])%mod;
        black[x] *= white[y];

        white[x] %= mod;
        black[x] %= mod;
    }
}

int main(){
   
   for(int i=0; i<100010; i++){
      black[i] = white[i] = 1;
   }

   ll n,x,y;
   cin>>n;

   for(int i=0; i<n-1; i++){
      cin>>x>>y;
      v[x].push_back(y);
      v[y].push_back(x);
   }
   dfs(1, -1);
   cout<<(white[1]+black[1])%mod<<endl;
} 
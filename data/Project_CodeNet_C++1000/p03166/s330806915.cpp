#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> adjin ;
vector<vector<ll>> adjout ;
vector<ll> topsort ;
vector<ll> visited ;
vector<ll> dp;

void dfs(ll a ){
    visited[a] = 1;
    for(auto c: adjout[a]){
         if(!visited[c]){
              dfs(c);
         }
    }
    topsort.push_back(a);

}

void solve(){
    adjin.clear(); adjout.clear(); topsort.clear(); visited.clear(); dp.clear();
ll n , m ;
cin >> n>> m;
for(ll i=0; i<n+1;i++){
     vector<ll> v1 , v2 ; adjin.push_back(v1); adjout.push_back(v2); visited.push_back(0);
     dp.push_back(0);
}

for(ll i=0; i<m ; i++){
     ll a , b ; cin >> a >> b; adjin[b].push_back(a); adjout[a].push_back(b);
}

for(ll i=1 ; i<=n ; i++){
    if(!visited[i]){ dfs(i);}
}
ll ans =0;

for(ll i=1; i<n;i++){
 
  ll a = topsort[n-1-i];
  for( auto d : adjin[a]){
     dp[a] = max( dp[a],dp[d]+1 ); ans = max(ans, dp[a]);
  }
}



 cout << ans << endl;


}

int main(){

 ll  n ;
  n=1;
  while(n--){solve();}
   
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

void chmax(ll &a, ll b){
  if( a < b){ swap(a,b);} return ;}

void chmin(ll &a, ll b){
  if( a > b){ swap(a,b);} return ;}

int main(){
ll N,Z,W; cin >> N >> Z >> W;
   vector<ll> A(N);
  for(ll i = 0; i < N; i++){ cin >> A[i];}
  
  vector<vector<ll>> dp(N, vector<ll> (2));
  
  for(ll i = N-1; i >= 0; i--){
    ll Y; 
    dp[i][0] = -INF;
    if(!i){ Y = W;} else{ Y = A[i-1];}
    
    chmax(dp[i][0], abs(Y-A[N-1]));
    
    for(ll j = i+1; j < N; j++){ chmax( dp[i][0], dp[j][1]);}
    
    ll X; 
    dp[i][1] = INF;
    if(!i){ X = Z;} else{ X = A[i-1];}
    
    chmin( dp[i][1], abs( X-A[N-1]));
    
    for(ll j = i+1; j < N; j++){ chmin( dp[i][1], dp[j][0]);}
  }
  
  cout << dp[0][0] << endl; return 0;}
    
    
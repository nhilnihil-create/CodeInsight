#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){
  fastio
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(ll i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a, a+n);
  ll dp[k+1];
  memset(dp, 0, sizeof(dp));
  for(ll i=1; i<=k; i++){
    if(i<a[0]){
      dp[i]=0;
    }
    else{
      for(ll j=0; j<n; j++){
        if(a[j]<=i){
          dp[i] = dp[i] || !dp[i-a[j]];
        }
      }
    }
  }
  if(dp[k]){
    cout<<"First\n";
  }
  else{
    cout<<"Second\n";
  }
  return 0;
}

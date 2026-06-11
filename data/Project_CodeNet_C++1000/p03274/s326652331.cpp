#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,k;
  cin>>n>>k;
  vector<ll> x(n); 
  rep(i,n) cin>>x[i];
  
  ll ans=1e9;
  rep(i,n-k+1){
    ans = min(ans,x[i+k-1]-x[i]+min(abs(x[i]),abs(x[i+k-1])));
  }
  cout<<ans<<endl;
}
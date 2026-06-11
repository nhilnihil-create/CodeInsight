#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<vector<ll>>f(n,vector<ll>(10));
  for(int i=0; i<n; i++){
   for(int j=0; j<10; j++) cin >> f[i][j]; 
  }
  vector<vector<ll>>p(n,vector<ll>(11));
  for(int i=0; i<n; i++){
   for(int j=0; j<11; j++) cin >> p[i][j]; 
  }
  
  ll ans=-10e9;
  for(int i=1; i<pow(2,10); i++){
    vector<ll>count(n,0);
    ll x=i;
    ll y=9;
    while(x>0){
     if(x & 1){
      for(int j=0; j<n; j++){
        if(f[j][y]==1)count[j]++;
      }
     }
      y--;
      x>>=1;
    }
    
    
    ll z=0;
    for(int j=0; j<n; j++){
      z+=p[j][count[j]];
    }
    ans=max(ans,z);
  }
  
  cout << ans << endl;
  
}
  
  

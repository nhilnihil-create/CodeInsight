#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll h,w;
  cin >> h >> w;
  vector<vector<ll>>c(10,vector<ll>(10));
  for(int i=0; i<=9; i++){
   for(int j=0; j<=9; j++){
    cin >> c[i][j]; 
   }
  }
  
  vector<vector<ll>>a(h,vector<ll>(w));
  for(int i=0; i<h; i++){
   for(int j=0; j<w; j++) cin >> a[i][j]; 
  }
  
  for(int k=0; k<=9; k++){
    for(int i=0; i<=9; i++){
      for(int j=0; j<=9; j++){
        c[i][j]=min(c[i][k]+c[k][j],c[i][j]);
      }
    }
  }
  
  ll ans=0; 
  for(int i=0; i<h; i++){
   for(int j=0; j<w; j++){
     if(a[i][j]==-1) continue;
     ans+=c[a[i][j]][1]; 
   }
  }
  
  cout << ans << endl;
  
  return 0;
  
  
}
  
  

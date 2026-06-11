#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll h,w,d,a;
  cin >> h >> w >> d;
  
  vector<vector<ll>>c(h*w+1,vector<ll>(2));
  for(int i=1; i<=h; i++){
   for(int j=1; j<=w; j++){
     cin >> a;
     c[a][0]=i;
     c[a][1]=j;
   }
  }
  
  ll q;
  cin >> q;
  
  vector<ll>ans(w*h+1);
  for(int i=1; i<=d; i++){
   for(int j=i+d; j<=h*w; j+=d){
     ll x=pow(pow(c[j][0]-c[j-d][0],2),0.5)+pow(pow(c[j][1]-c[j-d][1],2),0.5);
     ans[j]=ans[j-d]+x;
   }
  }
  
  for(int i=0; i<q; i++){
   ll l,r;
   cin >> l >> r;
   cout << ans[r]-ans[l] << endl; 
  }
  
}
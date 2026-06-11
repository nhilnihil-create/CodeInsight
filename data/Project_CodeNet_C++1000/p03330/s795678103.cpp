#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  
  int n,c;
  cin >> n >> c;
  vector<vector<int>>d(c,vector<int>(c));
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++) cin >> d[i][j];
  }
  
  int count0=0,count1=0,count2=0;
  vector<vector<int>>a(n,vector<int>(n));
  for(int l=0; l<n; l++){
    for(int m=0; m<n; m++) cin >> a[l][m];
  }
  
  vector<vector<ll>>ans0(c,vector<ll>(2));
  vector<vector<ll>>ans1(c,vector<ll>(2));
  vector<vector<ll>>ans2(c,vector<ll>(2));
  
  for(int i=0; i<c; i++){
    ans0[i][1]=i,ans1[i][1]=i,ans2[i][1]=i;
    for(int l=0; l<n; l++){
       for(int m=0; m<n; m++){
        int x=a[l][m]-1;
         if((l+m+2)%3==0) ans0[i][0]+=d[x][i];
         if((l+m+2)%3==1) ans1[i][0]+=d[x][i];
         if((l+m+2)%3==2) ans2[i][0]+=d[x][i];
         
     }
    }
  }
  
  sort(ans0.begin(),ans0.end());
  sort(ans1.begin(),ans1.end());
  sort(ans2.begin(),ans2.end());
  
  ll ans=10e9;
  for(int i=0; i<3; i++){
   for(int j=0; j<3; j++){
    for(int k=0; k<3; k++){
      if(ans0[i][1]==ans1[j][1] || ans1[j][1]==ans2[k][1] || ans2[k][1]==ans0[i][1]) continue;
      ll x = ans0[i][0]+ans1[j][0]+ans2[k][0];
      ans=min(ans,x);
    }
   }
  }
  
  cout << ans << endl;
  
}
  
  
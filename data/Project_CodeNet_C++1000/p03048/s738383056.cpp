#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int r1=n/r,g1=n/g;
  ll ans=0;
  for(int i=0;i<=r1;i++){
    for(int j=0;j<=g1;j++){
      ll p=n-i*r-j*g;
      if( p>=0 &&p%b==0){
        
        ans++;
      }
    }
  }
  cout << ans;
}
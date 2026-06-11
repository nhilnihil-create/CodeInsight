#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,j,a,d[200010][25]={};
  
  cin >> n;
  
  for (i=1;i<=n;i++){
    cin >> a;
    for (j=0;j<20;j++){
      d[i][j]=d[i-1][j]+a%2;
      a >>= 1;
    }
  }
  
  int l,r=1;
  ll ans=0;
  for (l=0;l<n;l++){
    bool ok=true;
    while (r<=n){
      for (j=0;j<20;j++){
        if (d[r][j]-d[l][j]>1){
          ok=false;
          break;
        }
      }
      if (!ok) break;
      r++;
    }
    r--;
    ans+=r-l;
    
  }
  
  cout << ans << endl;
  
  return 0;
}
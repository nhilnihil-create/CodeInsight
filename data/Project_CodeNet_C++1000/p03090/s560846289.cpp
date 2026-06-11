#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  cin>>n;
 
  int ans;
  ans=(n-2)*n/2;
  if(n%2!=0) ans++;
  cout<<ans<<endl;
  for(int i=1;i<n;i++){
    for(int j=i+1;j<=n;j++){
      if(n%2==0){if(j!=n-i+1) cout<<i<<" "<<j<<endl;}
      else {if(j!=n-i) cout<<i<<" "<<j<<endl;}
    }
  }
 
}
#include <bits/stdc++.h>
using namespace std;
signed main(){
  int n , s[1000005] , a[100005] , ans;
  cin>>n;
  s[0]=0,s[n+1]=0; 
  for(int i=1;i<=n;i++){
    cin>>s[i];
    if(i == n){
      a[n+1]=abs(s[i]);
      ans+=a[n+1];
    }
    a[i]=abs(s[i]-s[i-1]);
    ans+=a[i];
  }
  
  for(int i=1;i<=n;i++){
    cout<<ans-(a[i]+a[i+1])+abs(s[i-1]-s[i+1])<<endl;
  }
  return(0);
}
      
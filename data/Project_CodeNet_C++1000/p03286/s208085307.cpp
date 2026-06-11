#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  if (n==0){
    cout<<0<<endl;
    return 0;
  }
  
  string ans="";
  while (n!=0){
    int r=n%(-2);
    if (r<0) r+=2;
    ans+=(char)('0'+r);
    n-=r;
    n=n/(-2);
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
}
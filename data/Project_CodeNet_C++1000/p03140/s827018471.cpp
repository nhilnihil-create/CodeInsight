#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int n;cin>>n;
  string a,b,c;cin>>a>>b>>c;
  int ans=0;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]) {
      ans++;
      if(a[i]!=c[i]&&b[i]!=c[i]) ans++;
    } else {
      if(a[i]!=c[i]) ans++;
    }
  }
  cout << ans << endl;
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
 int n;
  string s;
  cin>>n>>s;
  int ans=300000;
  vector<int> sE(n+1),sW(n+1);
  sE[0]=0;
  sW[0]=0;
  for(int i=1;i<=n;i++){
    sE[i]=sE[i-1];
    sW[i]=sW[i-1];
    if(s[i-1]=='E') sE[i]++;
    else sW[i]++;
  }
  for(int i=1;i<=n;i++){
  ans=min(ans,sW[i-1]+(sE[n]-sE[i]));
  }
  cout<<ans<<endl;
}
    
  
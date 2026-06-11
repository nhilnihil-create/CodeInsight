#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  string s; cin>>s;
  vector<int> b(n+1,0),w(n+1,0);
  for(int i=1;i<=n;i++){
    if(s[i-1]=='#') b[i]=b[i-1]+1;
    else b[i]=b[i-1];
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='.') w[i]=w[i+1]+1;
    else w[i]=w[i+1];
  }int ans=b[0]+w[0];
  for(int i=0;i<=n;i++){
    ans=min(ans,b[i]+w[i]);
  }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  string s;
  cin>>s;
  int n=s.size();
  if(s[0]=='0'||s[n-1]=='1'){
    cout<<-1;
    return 0;
  }
  int u[n-1],v[n-1];
  int p=1;
  for(int i=1;i<=n/2;i++){
    if(s[i-1]!=s[n-i-1]){
      cout<<-1;
      return 0;
    }
    if(s[i-1]=='0')continue;
    while(p<i){
      u[p-1]=p;
     // u[n-2-(p-1)]=n-p;
      v[p-1]=i;
      //v[n-2-(p-1)]=n-i;
      p++;
    }
  }
  while(p<n){
    u[p-1]=p;
    v[p-1]=n;
    p++;
  }

  for(int i=0;i<n-1;i++){
    cout<<u[i]<<' '<<v[i]<<endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  int n=s.size();
  s=s+s;
  string ans="No";
  for(int i=0;i<n;i++){
    for(int j=i;j<i+n;j++){
      if(s[j]!=t[j-i]) break;
      else if(j==i+n-1) ans="Yes";
    }
  }
  cout<<ans<<endl;
}
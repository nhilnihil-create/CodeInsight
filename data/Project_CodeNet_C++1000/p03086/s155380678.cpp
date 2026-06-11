#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int ans=0;
  cin>>s;
  // for(int i=0;i<s.size();i++) {
  //   if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T') cnt++;
  //   else {
  //     ans=max(ans,cnt);
  //     cnt=0;
  //   }
  // }
  // ans=max(ans,cnt);
  for(int i=0;i<s.size();i++) {
    for(int j=i;j<s.size();j++) {
      bool can=true;
      for(int k=i;k<=j;k++) {
        if(s[k]!='A'&&s[k]!='C'&&s[k]!='G'&&s[k]!='T') {
          can=false;
        }
      }
      if(can) ans=max(ans,j-i+1);
    }
  }
  cout<<ans<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int len=(int)(S.size());
  bool ans=false;
  
  if(S.substr(0,7)=="keyence"||S.substr(len-7)=="keyence")
    ans=true;
  for(int i=1;i<7;i++){
    string a=S.substr(0,i);
    string b=S.substr(len-7+i);
    if(a+b=="keyence")
      ans=true;
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

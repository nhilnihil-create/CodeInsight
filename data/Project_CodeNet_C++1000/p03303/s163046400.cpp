#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,ans="";
  int w;
  cin>>s >>w;
  
  for(int i=0;i<(int)s.size();i+=w){
    ans+=s[i];
  }
  
  cout<<ans<<endl;
  return 0;
}
  
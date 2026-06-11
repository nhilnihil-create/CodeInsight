#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,ans;
  int w,i;
  cin>>s>>w;
  for(i=0;i<s.size();i++) if(!(i%w))ans+=s[i];
  cout<<ans<<endl;
}

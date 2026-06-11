#include<bits/stdc++.h>
using  namespace std;
signed main(){
  string s,c="keyence";
  int a,b=0;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]!=c[i]){
      a=i;
      break;
    }
  }
  for(int i=s.size();i>=0;i--){
    b++;
    if(s[i-1]!=c[c.size()-b]){
      b--;
      break;
    }
  }
  if(a+b>=c.size()||a==c.size()||b==c.size()||a+1==c.size()&&s.size()==c.size()) cout<<"YES\n";
  else cout<<"NO\n";
}
#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
  string s;
  cin>>s;
  bool ok=true;
  for(int i=1;i<s.size();i++){
    if(s[i]-'0'<9){ok=false;s[i]='9';}
  }
  if(!ok){s[0]=(s[0]-'0'-1)+'0';}
  int count=0;
  for(int i=0;i<s.size();i++){
    count+=s[i]-'0';
  }
  
  cout<<count<<endl;
  return 0;}
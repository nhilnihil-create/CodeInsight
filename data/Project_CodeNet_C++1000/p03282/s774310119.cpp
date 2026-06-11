#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  long long a;
  cin>>s>>a;
  if(s.size()==1){
    cout<<s[0]<<"\n";
    return 0;
  }
  int cnt=0;
  for(int i=0;i<s.size();i++){
   	if(s[i]!='1') break;
    cnt++;
  }
  if(a<=cnt)cout<<"1\n";
  else cout<<s[cnt]<<"\n";
  return 0;
}
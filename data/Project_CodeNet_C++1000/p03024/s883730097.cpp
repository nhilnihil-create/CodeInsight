#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int count=0;
  for(int i=0;i<s.size();i++){
      if(s.at(i)=='o') count++;
  }
  if(15-s.size()+count>=8) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

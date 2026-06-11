#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int kazu=0;
  if(s.size()<15)kazu+=15-s.size();
  for(int i=0;i<s.size();i++){
    if(s[i]=='o')kazu++;
  }
  if(kazu>=8)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
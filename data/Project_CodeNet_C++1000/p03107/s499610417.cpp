#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int kotae=0;
  int ichi=0;
  int zero=0;
  int n=s.size();
  for(int i=0;i<n;i++){
    if(s[i]=='0')zero++;
    else ichi++;
  }
  kotae=min(ichi,zero)*2;
  cout<<kotae<<endl;
  return 0;
}
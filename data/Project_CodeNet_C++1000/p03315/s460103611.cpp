#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin>>s;
  int kazu=s.size();
  int kotae=0;
  for(int i=0;i<kazu;i++){
    if(s[i]=='+')kotae++;
    if(s[i]=='-')kotae--;
  }
  cout<<kotae<<endl;
  return 0;
}
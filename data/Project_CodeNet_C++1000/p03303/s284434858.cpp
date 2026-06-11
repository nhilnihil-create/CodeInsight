#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n;
  cin >>n;
  for(int i=0;i<s.size();i+=n){
    if(i<s.size())cout<<s[i];
  }
  cout<<endl;
  return 0;
}
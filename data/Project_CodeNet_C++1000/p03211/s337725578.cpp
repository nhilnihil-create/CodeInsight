#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin>>s;
  int a=100100;
  for(int i=0; i<s.size()-2; i++){
    int n=atoi(s.substr(i,3).c_str());
    a=min(a,abs(n-753));
  }
  cout<<a;
}
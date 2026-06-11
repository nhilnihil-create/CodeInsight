#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin>>s;
  vector<char> v;
  for(char c:s) v.push_back(c);
  int s0=count(v.begin(),v.end(),'0'),s1=v.size()-s0;
  cout<<abs(min(s0,s1)*2);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  int i;
  string x = " ";
  string y = " ";
  vector<char> xx;
  vector<char> yy;
  for(i=0;i<s.size();i++) xx.push_back(s[i]);
  for(i=0;i<t.size();i++) yy.push_back(t[i]);
  sort(xx.begin(),xx.end());
  sort(yy.begin(),yy.end());
  for(i=0;i<s.size();i++) x += xx[i];
  for(i=t.size()-1;i>=0;i--) y += yy[i];
  if(x<y) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
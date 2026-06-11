#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  vector<int> ans(s.size(), 0);
  int m = 0;
  for (int i=0 ; i<s.size() ; i++){
    if (s.at(i)=='A' || s.at(i)=='C' || s.at(i)=='G' || s.at(i)=='T')
      ans.at(m)++;
    else
      m++;
  }
  
  sort(ans.begin(), ans.end());
  
  cout << ans.at(s.size()-1) << endl;
}
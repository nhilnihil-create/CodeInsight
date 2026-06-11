#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;

  set<string> ans;

  for(int i=0;i<s.size();i++) {
    int lim = min(5, (int)s.size() - i);
    for(int j=1;j<=lim;j++) {
      string ss = s.substr(i, j);
      ans.emplace(ss);
    }
  }

  set<string>::iterator it = next(ans.begin(), k-1);

  cout << *it << endl; 
}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


int main() {

  string s;
  cin >> s;
  vector<int> vals =  {0};
  string ns;

  for(int i=0; i<s.size(); i++) {
    if(s[i] == 'x') {
      vals.back()++;
      continue;
    }
    vals.push_back(0);
    ns += " ";
    ns.back() = s[i];
  }

  for(int i=0; i<ns.size(); i++) {
    if(ns[i] != ns[ns.size()-1-i]){
      cout << -1 << endl;
      return 0;
    }

  }
  int ans = 0;
  for(int i=0; i<vals.size()/2; i++) {
    ans += abs(vals[i] - vals[vals.size()-1-i]);

  }
  cout << ans << endl;


  return 0;
}

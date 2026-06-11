#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  
  int n = s.size();
  bool ok = false;
  
  rep(i,n) {
    s = s.back() + s.substr(0,n-1);
    if (s == t) {
      ok = true;
      break;
    }
  }
  
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
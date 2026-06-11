#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s,t;
  cin >> s >> t;
  bool ans  = false;
  rep(i,s.size()){
    if(s == t) ans  = true;
    s = s.back() + s.substr(0,s.size()-1);
  }
  puts(ans?"Yes":"No");
 }

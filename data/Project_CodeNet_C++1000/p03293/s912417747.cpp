#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  string s,t;
  cin >> s >> t;
  if(s==t) {
    cout << "Yes" << endl;
    return 0;
  }
  bool ok = false;
  for(int i = 1; i < s.size(); ++i){
    string u = s.substr(i)+s.substr(0,i);
    if(u==t) {
      ok=true;
      break;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
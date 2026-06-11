#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s, t="keyence", u="";
  cin >> s;

  rep(i,s.size()) {

    if(s.at(i)==t.at(i)) {
      u += t.at(i);
      if(u==t) {
        cout << "YES" << endl;
      }
      continue;
    }

    for(int j = i; j<s.size(); j++) {
      if(u+s.substr(j)==t) {
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
    return 0;
  }
}
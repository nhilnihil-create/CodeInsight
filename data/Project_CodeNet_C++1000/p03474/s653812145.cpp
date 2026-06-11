#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  if(s.size() != a + b + 1) {
    cout << "No" << endl;
    return 0;
  }
  else {
    if(s[a] != '-') {
      cout << "No" << endl;
      return 0;
    }
    else {
      rep(i, s.size()) {
        if(i == a) continue;
        if(!(0 <= (s[i] - '0') && (s[i] - '0') <= 9)) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
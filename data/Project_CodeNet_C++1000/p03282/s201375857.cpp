#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  rep(i,min((ll)s.size(),k)) {
    if (s[i]!='1') {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << '1' << endl;
  return 0;

}
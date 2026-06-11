#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  int cnt = 0;
  if(s[0] != 'A') ok = false;
  for(int i = 1; i < (int)s.size(); i++) {
    if(isupper(s[i])) {
      if(i == 1 || i == (int)s.size() - 1 || s[i] != 'C') ok = false;
      cnt++;
    }
  }
  if(cnt != 1) ok = false;
  
  if(ok) cout << "AC" << endl;
  else cout << "WA" << endl;
  return 0;
}
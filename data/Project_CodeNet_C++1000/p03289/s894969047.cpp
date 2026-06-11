#include<iostream>
#include<string>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

string f(string s) {
  if (s[0] != 'A') return "WA";

  bool ok = false;
  rep(i,2,s.size()-2) {
    if (s[i] == 'C') {
      if (ok) {
        ok = false;
        break;
      } else {
        ok = true;
      }
    }
  }

  if (!ok) return "WA";

  for (char c:s) {
    if (c == 'A' || c == 'C') continue;
    if (c < 'a' || 'z' < c) return "WA";
  }

  return "AC";
}

int main() {
  string s;
  cin >> s;
  cout << f(s) << endl;
  return 0;
}

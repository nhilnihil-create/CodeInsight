#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;
bool islow(char c) {
  return ('a' <= c && c <= 'z');
}
int main() {
  string s;
  cin >> s;
  int cf = 0;
  if (s[0] == 'A' && islow(s[1]) && islow(s[s.size() - 1])) {
    for (int i = 2; i < (int) (s.size() - 1); ++i) {
      if (s[i] == 'C') {
        cf++;
      } else if (!islow(s[i])) {
        cout << "WA";
        return 0;
      }
    }
  } else {
    cout << "WA";
    return 0;
  }
  if (cf == 1)
    cout << "AC";
  else
    cout << "WA";
}

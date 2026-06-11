#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = s.size();
  if(a==2) cout << s << endl;
  else {
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}

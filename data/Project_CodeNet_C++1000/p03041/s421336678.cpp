#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  
  s[b-1] = tolower(s[b-1]);
  cout << s << endl;
  
}
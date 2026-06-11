#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;

  cin >> a >> b >> s;

  s.at(b-1) = tolower(s.at(b-1));

  cout << s << endl;
}

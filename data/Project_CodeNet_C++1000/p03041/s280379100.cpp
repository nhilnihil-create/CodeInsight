#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> s >> k >> s;

  s[k-1] += 'a' - 'A';
  cout << s << endl;
}
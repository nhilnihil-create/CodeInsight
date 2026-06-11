#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size(), c = 0;
  for(int i = 0; i < n; i++)c += (i + s[i]) % 2;
  cout << min(c, n - c) << endl;
}
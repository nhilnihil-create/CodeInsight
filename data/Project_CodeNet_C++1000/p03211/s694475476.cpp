#include <bits/stdc++.h>
using namespace std;
int main()
  {string S; cin >> S;
  int m(1e5); for (int i{}; i < S.size() - 2; ++i) m = min(m, abs(753 - stoi(S.substr(i, 3))));
  cout << m;}
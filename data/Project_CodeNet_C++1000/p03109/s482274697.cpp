#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.at(5) == '1') cout << "TBD" << endl;
  else if (s.at(6) <= '4') cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}

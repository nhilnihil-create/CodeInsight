#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  string abc = "abc";
  if (s == abc) cout << "Yes" << endl;
  else cout << "No" << endl;
}

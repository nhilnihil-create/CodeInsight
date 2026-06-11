#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  regex R ("A?KIHA?BA?RA?");
  cout << ((regex_match(S, R)) ? "YES" : "NO") << "\n";
}

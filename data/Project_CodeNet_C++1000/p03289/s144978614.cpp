#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  regex R ("A[a-z][a-z]*C[a-z]*[a-z]");
  cout << ((regex_match(S, R)) ? "AC" : "WA") << "\n";
}
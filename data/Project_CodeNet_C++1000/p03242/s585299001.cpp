#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  S = regex_replace(S, regex("9"), "x");
  S = regex_replace(S, regex("1"), "9");
  S = regex_replace(S, regex("x"), "1");
  cout << S << "\n";
}
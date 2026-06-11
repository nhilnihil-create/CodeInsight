#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string A, B;
  string S;
  cin >> A >> B >> S;

  // TODO: 埋め込みできるのかな
  regex re = regex("^[0-9]{" + A + "}-[0-9]{" + B + "}$");

  // 全体一致
  bool isValid = regex_match(S, re);

  cout << (isValid ? "Yes" : "No") << endl;
}
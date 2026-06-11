#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  bool ans = false;
  if(S.at(0) != S.at(1) && S.at(0) != S.at(2) && S.at(1) != S.at(2))
    ans = true;

  if(ans == true) cout << "Yes" << endl;
  if(ans == false) cout << "No" << endl;
}
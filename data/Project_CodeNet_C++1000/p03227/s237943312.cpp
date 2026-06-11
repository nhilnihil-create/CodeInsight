#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S.size() == 3) swap(S.at(0), S.at(2));
  cout << S << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  int w; cin >> w;
  for (int i = 0; i < S.size(); i = i + w) cout << S.at(i);
  cout << endl;
}
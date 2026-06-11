#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  vector<string> C(2);
  string s;
  cin >> s;
  C.at(0) = s;
  cin >> s;
  C.at(1) = s;
  if (C.at(0).at(0) == C.at(1).at(2)
      && C.at(0).at(1) == C.at(1).at(1)
      && C.at(0).at(2) == C.at(1).at(0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> C(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> C.at(i).at(j);
    }
  }
  for (int a1 = 0; a1 <= 100; a1++) {
    vector<int> B = {C.at(0).at(0) - a1, C.at(1).at(0) - a1, C.at(2).at(0) - a1};
    vector<int> A = {C.at(0).at(0) - B.at(0), C.at(0).at(1) - B.at(0), C.at(0).at(2) - B.at(0)};
    bool b = 1;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (B.at(i) + A.at(j) != C.at(i).at(j)) b = 0;
      }
    }
    if (b) return cout << "Yes" << "\n", 0;
  }
  cout << "No" << "\n";
}
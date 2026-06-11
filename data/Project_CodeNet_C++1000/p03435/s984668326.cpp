#include <bits/stdc++.h>
using namespace std;

int sum(vector<vector<int>> &C) {
  int s = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) s += C.at(i).at(j);
  }
  return s;
}

int diagonal(vector<vector<int>> &C) {
  int d = 0;
  for (int i = 0; i < 3; i++) d += C.at(i).at(i);
  return d;
}

int main() {
  int i, j;
  vector<vector<int>> C(3, vector<int>(3));
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) cin >> C.at(i).at(j);
  }
  
  string s = "No";
  if (sum(C) == diagonal(C) * 3) s = "Yes";
  
  cout << s << endl;
}

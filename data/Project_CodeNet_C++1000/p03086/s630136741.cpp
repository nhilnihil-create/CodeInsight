#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  vector<int> jug(10);
  cin >> S;

  for (int i = 0; i < S.size(); i++) {
    for (int j = i; j < S.size(); j++) {
      if (S.at(j) == 'A' || S.at(j) == 'C' || S.at(j) == 'G' || S.at(j) == 'T') {
        jug.at(i)++;
      }
      else {
        break;
      }
    }  
  }
  sort(jug.begin(), jug.end(), greater<>());
  cout << jug.at(0) << endl;
}
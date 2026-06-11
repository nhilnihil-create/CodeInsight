#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S; cin >> S;
  vector<string> v = { "", "A" };
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          string T = v.at(i) + "KIH" + v.at(j) + "B" + v.at(k) + "R" + v.at(l);
          if (S == T) {
            cout << "YES" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
}
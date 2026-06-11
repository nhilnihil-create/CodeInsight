#include <bits/stdc++.h>
using namespace std;
 
int main () {
  vector<int> ant(5);
  for (int i = 0; i < 5; i++) {
    cin >> ant.at(i);
  }
  int k;
  cin >> k;
  bool ok = true;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (abs(ant.at(i) - ant.at(j)) > k) {
        ok = false;
      }
    }
  }
  if (ok) {
    cout << "Yay!" << endl;
  }
  else {
    cout << ":(" << endl;
  }
}
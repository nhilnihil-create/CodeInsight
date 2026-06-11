#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin >> S;
  int memo = 0;
  int k = S.size();
  for (int i = 0; i < k; i++) {
    if (S.at(i) == '1') {
      memo++;
    }
  }
  cout << min(k - memo, memo) * 2 << endl;
}
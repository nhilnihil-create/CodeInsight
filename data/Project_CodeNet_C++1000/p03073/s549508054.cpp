#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int N = S.size();
  
  int num01 = 0;
  int num10 = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      if (S[i] == '0') {
        num10++;
      } else {
        num01++;
      }
    } else {
      if (S[i] == '1') {
        num10++;
      } else {
        num01++;
      }
    }
  }
  
  cout << min(num10, num01) << endl;
}
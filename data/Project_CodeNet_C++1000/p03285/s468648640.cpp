#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  bool flag = false;
  
  int maxC = N / 4 + 1;
  int maxD = N / 7 + 1;
  
  for (int c = 0; c < maxC; c++) {
    for (int d = 0; d < maxD; d++) {
      if ((4 * c + 7 * d) == N) {
        flag = true;
      }
    }
  }
  
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
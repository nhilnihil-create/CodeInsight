#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b;
  cin >> N;
  
  bool exist = false;
  
  for (int a = 0; a <= N/4+1; ++a) {
    for (int b = 0; b <= N/7+1; ++b) {
      int total = 4*a + 7*b; // 合計金額
      if (total == N) exist = true; // 合計金額が N に一致したら true
    }
  }
  
  if (exist) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

}
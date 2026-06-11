#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool flag = false;

  for (int i=0; i<=25; i++) {
    for (int j=0; j<=14; j++) {
      if (i*4 + j*7 == N) {
        flag = true;
        break;
      }
    }
    if (flag == true) break;
  }

  cout << ( flag ? "Yes" : "No" ) << endl;
}

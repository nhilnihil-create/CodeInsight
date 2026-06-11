#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  for(int i = 1; i <= n; i+= 2) {
    int yaku = 0;
    for(int j = 1; j <= n; j++) {
      if(i % j == 0) yaku++;
    }
    if(yaku == 8) cnt++;
  }
  cout << cnt;
}
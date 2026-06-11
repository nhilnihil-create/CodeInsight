#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  long long x, y;
  cin >> x >> y;
  
  long long z = x, cnt = 0;
  while (z <= y) {
    cnt++;
    z *= 2;
  }
  cout << cnt << endl;
}
    
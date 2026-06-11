#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m, a, b;
  cin >> n >> m;
  a = m/n;
  for (int64_t i=a; i>=1; i--){
    if (m%i==0){
      cout << i;
      return 0;
    }
  }
  return 0;
}

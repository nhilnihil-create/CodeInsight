#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int ans = 0;
  
  for (int i = A; i <= B; i++) {
    int tmp1, tmp2, tmp3, tmp4;
    tmp1 = i / 10000;
    tmp2 = (i / 1000) % 10;
    tmp3 = (i / 10) % 10;
    tmp4 = i % 10;
  
    if (tmp1 == tmp4 && tmp2 == tmp3) {
      ans++;
    }
  }
  
  cout << ans << endl;
}

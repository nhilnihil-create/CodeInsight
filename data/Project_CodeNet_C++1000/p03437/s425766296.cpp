#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;
  
  if(x % y == 0){
    cout << -1 << endl;
    return 0;
  }
  long long k = 1;
  while(1){
    long long ans = k * x;
    if(ans % y == 0){
      k++;
      continue;
    }
    cout << ans << endl;
    return 0;
  }
}
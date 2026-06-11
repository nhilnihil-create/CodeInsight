#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t k, a, b;
  cin >> k >> a >> b;
  
  if (b-a <= 2) cout << k + 1 << endl;
  else {
    if (k - (a-1) <= 1) cout << k + 1 << endl;
    else {
      k -= (a-1);
      if (k % 2 == 0) cout << k/2*(b-a) + a << endl;
      else cout << k/2*(b-a) + (a+1) << endl;
    }
  } 
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int max_1 = max(max(a,b), c);
  int max_2 = max_1;
  for(int i = 0; i < k; i++){
   max_2 *= 2;
  }
  cout << a + b + c + max_2 - max_1 << endl;
  return 0;
}
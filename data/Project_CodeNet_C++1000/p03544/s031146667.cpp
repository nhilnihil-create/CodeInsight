#include <bits/stdc++.h>
using namespace std;

/*
uint64_t lucas(int num) {
  if (num == 0) { 
    return 2;
  } else if (num == 1) {
    return 1;
  }  
  return lucas(num-2) + lucas(num-1);
}
*/

uint64_t lucas(int num) {
  uint64_t ans = 0;
  uint64_t n_1 = 0;
  uint64_t n_2 = 0;
  for (int i=0; i<=num; i++) { 
    if (i == 0) {
      n_2 = 2;
      if (num == 0) {
        return 2;
      }
    } else if (i == 1) {
      n_1 = 1;
      if (num == 1) {
        return 1;
      }
    } else { 
      ans = n_1 + n_2;
      n_2 = n_1;
      n_1 = ans;
    }
  }
  return ans;
}
      
int main() {
  int num;
  cin >> num;
  cout << lucas(num) << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  
  cin >> A >> B >> C >> D;
  
  int sum_l = A + B;
  int sum_r = C + D;
  
  if (sum_l > sum_r) {
    cout << "Left" << endl;
  }
  else if (sum_l < sum_r) {
    cout << "Right" << endl;
  }
  else {
    cout << "Balanced" << endl;
  }
  
  return 0;
}
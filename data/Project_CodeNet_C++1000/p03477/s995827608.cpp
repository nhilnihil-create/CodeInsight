#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int sum_L = A + B;
  int sum_R = C + D;
  if (sum_L < sum_R) {
    cout << "Right" << endl;
  }
  if (sum_L == sum_R) {
    cout << "Balanced" << endl;
  }
  if (sum_L > sum_R) {
    cout << "Left" << endl;
  }
}

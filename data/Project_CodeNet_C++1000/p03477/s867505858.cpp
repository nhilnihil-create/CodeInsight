#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int x = A + B - C - D;
  if (x > 0)cout << "Left" << endl;
  else if (x < 0)cout << "Right" << endl;
  else cout << "Balanced" << endl;
}
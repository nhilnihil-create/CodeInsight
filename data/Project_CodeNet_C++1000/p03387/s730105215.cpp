#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int max_num = max(A, max(B, C));
  int empty_area = (3 * max_num) - (A + B + C);

  if (empty_area % 2 == 0) {
    cout << (empty_area / 2) << endl;
  } else {
    cout << ((empty_area + 3) / 2) << endl;
  }
}

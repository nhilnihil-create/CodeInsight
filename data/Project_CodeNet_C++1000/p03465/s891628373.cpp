/**
 *    author:  tourist
 *    created: 09.01.2018 10:40:48       
**/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2018;
const int MAX_A = 2018;

int main() {
  int n;
  cin >> n;
  bitset<MAX_N * MAX_A> b;
  b[0] = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    b |= (b << a);
    sum += a;
  }
  for (int j = (sum + 1) / 2; j <= sum; j++) {
    if (b[j] == 1) {
      cout << j << endl;
      break;
    }
  }
  return 0;
}

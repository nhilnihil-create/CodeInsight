#include <bits/stdc++.h>

using namespace std;

int main () {
  
  int A, B, C, K, m, j, l;

  cin >> A >> B >> C >> K;

  if (A >= B && A >= C) {
    m = A;
    j = B;
    l = C;
  } else if (B >= A && B >= C) {
    m = B;
    j = A;
    l = C;
  } else {
    m = C;
    j = B;
    l = A;
  }

  for (int i = 0; i < K; i++) {
    m = m * 2;
  }

  cout << m + j + l << endl;

  return 0;
}
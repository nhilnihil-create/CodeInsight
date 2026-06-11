#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D, E, K;
  cin >> A >> B >> C >> D >> E >> K;
  
  int I = B - A;
  int J = C - A;
  int Z = D - A;
  int L = E - A;
  int M = C - B;
  int N = D - B;
  int O = E - B;
  int P = D - C;
  int Q = E - C;
  int R = E - D;
  
  if (I > K || J > K || Z > K || L > K || M > K || N > K || O > K || P > K || Q > K || R > K) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
     
int main() {
  double N, T, A, a, b = 0;
  cin >> N >> T >> A;
  vector<int> H(N),array(N),marray(N);
  for (int i = 0; i < N; i++) cin >> H[i];
 
  int answer = 1;
  for (int i = 0; i < N; i++) {
    a = T-H[i]*0.006-A;
    if (a < 0) a = -a;
    if (i == 0) b = a;
    if (a < b) {
      b = a;
      answer = i + 1;
    }
  }
  cout << answer << endl;
}
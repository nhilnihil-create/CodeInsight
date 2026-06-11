#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  int ans;
  for (int i = min(A,B); i > 0; i--) {
    if (A % i == 0 && B % i == 0) {
      K--;
      if (K==0) {
        cout << i << endl;
        return 0;
      }
    }
  }
}

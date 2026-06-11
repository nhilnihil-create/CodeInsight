#include <bits/stdc++.h>
using namespace std;

void solve(long long A, long long B) {
  if (A <= 8 && B <= 8) {
    cout << "Yay!";
  } else {
    cout << ":(";
  }
  cout << endl;
}

int main() {
  long long A;
  scanf("%lld", &A);
  long long B;
  scanf("%lld", &B);
  solve(A, B);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll K, A, B;
  cin >> K >> A >> B;
  if (B-A < 3) {
    cout << K+1 << endl;
    return 0;
  }
  ll L = K-A+1;
  cout << L/2 * (B-A) + A + L%2 << endl;
}
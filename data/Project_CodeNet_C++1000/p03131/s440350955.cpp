#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll K, A, B;
  cin >> K >> A >> B;
  ll biscuit = 1;
  for (ll i = 0; i < K; i++) {
    if (i < K-1 && biscuit >= A) {
      biscuit += max(B-A,2LL);
      i++;
    }
    else biscuit += 1;
  }
  cout << biscuit << endl;
}

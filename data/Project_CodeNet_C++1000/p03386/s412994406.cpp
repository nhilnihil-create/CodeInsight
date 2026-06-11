#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll A, B, K;
  cin >> A >> B >> K;
  if(B - A + 1 < 2 * K) {
    for(ll i = A; i <= B; i++) {
      cout << i << endl;
    }
  }
  else {
    for(ll i = 0; i < K; i++) {
      cout << A + i << endl;
    }
    for(ll i = K - 1; i >= 0; i--) {
      cout << B - i << endl;
    }
  }
}
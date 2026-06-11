#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int A, B, K; cin >> A >> B >> K;
  rep(i,K) {
    if (i%2==0) {
      A /= 2;
      B += A;
    }
    else {
      B /= 2;
      A += B;
    }
  }
  cout << A << " " << B << endl;
  return 0;
}
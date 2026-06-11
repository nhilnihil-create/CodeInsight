#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string L = "Left";
const string E = "Balanced";
const string R = "Right";

void solve(ll A, ll B, ll C, ll D) {
  auto l = A + B;
  auto r = C + D;
  cout << (l > r ? L : (l < r) ? R : E) << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  ll D;
  cin >> D;
  solve(A, B, C, D);
  return 0;
}

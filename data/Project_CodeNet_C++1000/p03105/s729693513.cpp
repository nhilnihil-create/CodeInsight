#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(ll A, ll B, ll C) {
  cout << min(C,B/A) << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  solve(A, B, C);
  return 0;
}

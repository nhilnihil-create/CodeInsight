#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

void solve(ll A, ll B, ll C) { cout << max({A, B, C}) * 9 + A + B + C << endl; }

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

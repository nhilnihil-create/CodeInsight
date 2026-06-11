#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(ll a, ll b, ll c, ll d) {
  bool pred = abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d);
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll a;
  cin >> a;
  ll b;
  cin >> b;
  ll c;
  cin >> c;
  ll d;
  cin >> d;
  solve(a, b, c, d);
  return 0;
}

#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string YES = "Odd";
const string NO = "Even";

void solve(ll a, ll b) { cout << (a * b % 2 ? YES : NO) << endl; }

int main() {
  ll a;
  cin >> a;
  ll b;
  cin >> b;
  solve(a, b);
  return 0;
}

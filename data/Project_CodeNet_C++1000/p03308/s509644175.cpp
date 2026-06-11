#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
  int a;
  cin >> a;
  vi b(a);
  rep(i, a) {
    cin >> b.at(i);
  }
  sort(ALL(b));
  cout << b.at(a-1)-b.at(0);
}
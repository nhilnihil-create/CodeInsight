#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  int a;
  cin >> a;
  int b = a/100;
  b *= 111;
  if(a<=b) cout << b;
  else cout << b + 111;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

int main() {
  vi a(100001,0);
  rep(i, 100000){
    a.at(i) = i*i;
  }
  int b;
  cin >> b;
  cout << a.at(sqrt(b));
}
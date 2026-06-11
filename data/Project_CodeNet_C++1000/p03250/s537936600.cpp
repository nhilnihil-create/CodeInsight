#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c; cin >> a >> b >> c;
  cout << max({a, b, c}) * 9 + (a+b+c) << endl;
  return 0;
}
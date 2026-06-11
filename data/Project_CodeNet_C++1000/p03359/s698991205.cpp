#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b; cin >> a >> b;
  if (a > b) cout << a - 1 << endl;
  else cout << a << endl;
  return 0;
}
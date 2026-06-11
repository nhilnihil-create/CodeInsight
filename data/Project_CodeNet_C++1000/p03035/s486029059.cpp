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
  int A, B;
  cin >> A >> B;
  if (A >= 13) cout << B << endl;
  else if (A >= 6) cout << B/2 << endl;
  else cout << 0 << endl;
  return 0;
}
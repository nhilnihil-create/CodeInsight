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
  int s; cin >> s;
  vector<int> a(1000010);
  ++a[s];
  int i = 1;
  while (true) {
    ++i;
    if (s%2==0) s /= 2;
    else s = 3 * s + 1;
    ++a[s];
    if (a[s] >= 2) break;
  }
  cout << i << endl;
  return 0;
}
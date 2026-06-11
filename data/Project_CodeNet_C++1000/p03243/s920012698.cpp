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
  int N; cin >> N;
  if (N > 888) cout << 999 << endl;
  else if (N > 777) cout << 888 << endl;
  else if (N > 666) cout << 777 << endl;
  else if (N > 555) cout << 666 << endl;
  else if (N > 444) cout << 555 << endl;
  else if (N > 333) cout << 444 << endl;
  else if (N > 222) cout << 333 << endl;
  else if (N > 111) cout << 222 << endl;
  else cout << 111 << endl;
  return 0;
}
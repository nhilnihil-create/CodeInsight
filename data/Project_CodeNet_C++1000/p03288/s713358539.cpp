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
  int R; cin >> R;
  if (R < 1200) cout << "ABC" << endl;
  else if (R < 2800) cout << "ARC" << endl;
  else cout << "AGC" << endl;
  return 0;
}
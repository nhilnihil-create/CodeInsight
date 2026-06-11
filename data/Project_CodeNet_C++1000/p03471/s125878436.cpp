#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n, y;
  cin >> n >> y;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j+i <= n; j++) {
      int k = n-(i+j);
      if (10000*i + 5000*j + 1000*k == y) {
        cout << i << ' ' << j << ' ' << k << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}
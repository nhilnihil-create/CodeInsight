#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <random>
using namespace std;
int main() {
  vector <int> n(4);
  for (int i = 0; i < 4; i++) {
	  cin >> n[i];
	}
  sort(n.begin(), n.end());
  int m = n[0] + 10 * n[1] + 100 * n[2] + 1000 * n[3];
  if (m == 9741) {
	  cout << "YES" << endl;
	} else {
	  cout << "NO" << endl;
	}
  return 0;
}

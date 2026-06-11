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
  vector <int> c(5, 0);
  for (int i = 0; i < 3; i++) {
	  int a, b;
	  cin >> a >> b;
	  c[a]++;
	  c[b]++;
	}
  sort(c.begin(), c.end());
  if (c[1] == 1 && c[2] == 1 && c[3] == 2) {
	  cout << "YES" << endl;
	} else {
	  cout << "NO" << endl;
	}
  return 0;
}

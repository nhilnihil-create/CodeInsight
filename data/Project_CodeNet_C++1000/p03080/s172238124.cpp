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
  int n;
  string s;
  cin >> n >> s;
  int r = 0;
  for (int i = 0; i < n; i++) {
	  r += (s[i] == 'R');
	}
  if (r > n - r) {
	  cout << "Yes" << endl;
	} else {
	  cout << "No" << endl;
	}
  return 0;
}

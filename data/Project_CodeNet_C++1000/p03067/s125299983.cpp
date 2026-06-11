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
  int a, b, c;
  cin >> a >> b >> c;
  if ((c - a) * (b - c) > 0) {
	  cout << "Yes" << endl;
	} else {
	  cout << "No" << endl;
	}
  return 0;
}

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
  cin >> n;
  vector <int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
	  cin >> a[i];
	  sum += a[i];
	}
  int m  = 1e9;
  int mn = -1;
  for (int i = 0; i < n; i++) {
	  if (abs(sum - n * a[i]) < m) {
		  m  = abs(sum - n * a[i]);
		  mn = i;
		}
	}
  cout << mn << endl;
  return 0;
}

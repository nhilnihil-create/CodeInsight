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
  string s;
  cin >> s;
  for (int i = 0; i < 15; i++) {
	  s += 'o';
	}
  int w = 0;
  for (int i = 0; i < 15; i++) {
	  if (s[i] == 'o') {
		  w++;
		}
	}
  if (w >= 8) {
	  cout << "YES\n";
	} else {
	  cout << "NO\n";
	}
  return 0;
}

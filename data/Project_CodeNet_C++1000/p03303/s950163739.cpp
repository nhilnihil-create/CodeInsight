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
  string S;
  int w;
  cin >> S >> w;
  int l = S.length();
  for (int i = 0; i < l; i += w) {
	  cout << S[i];
	}
  cout << endl;
  return 0;
}

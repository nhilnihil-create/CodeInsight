#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int a, b;
  cin >> a >> b;
  if (a <= 5) {
    cout << 0 << endl;
  } else if (a <= 12) {
    cout << b / 2 << endl;
  } else {
    cout << b << endl;
  }
  return 0;
}
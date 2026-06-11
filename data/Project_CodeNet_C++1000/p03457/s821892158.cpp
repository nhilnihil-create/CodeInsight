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
  int t1;
  int t2 = 0;
  int a1;
  int a2 = 0;
  int b1;
  int b2 = 0;

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t1 >> a1 >> b1;
    int s = abs(a1 - a2) + abs(b1 - b2);
    if (s > (t1 - t2) || ((s % 2) != ((t1 - t2) % 2))) {
      cout << "No" << endl;

      return 0;
    }
    a2 = a1;
    b2 = b1;
    t2 = t1;
  }
  cout << "Yes" << endl;

  return 0;
}
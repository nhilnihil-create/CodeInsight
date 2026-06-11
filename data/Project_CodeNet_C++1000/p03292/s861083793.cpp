#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  cout << max(a[0], max(a[1], a[2])) - min(a[0], min(a[1], a[2])) << endl;
}
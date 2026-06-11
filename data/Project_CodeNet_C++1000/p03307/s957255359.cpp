#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  if (n & 1)
    cout << n * 2;
  else
    cout << n;
  cout << endl;
  return 0;
}
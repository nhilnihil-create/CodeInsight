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

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> vec;
  for (int i = 1; i <= a * b; ++i) {
    if (a % i == 0 && b % i == 0) {
      vec.push_back(i);
    }
  }
  sort(vec.rbegin(), vec.rend());
  cout << vec[k - 1] << endl;
}
       
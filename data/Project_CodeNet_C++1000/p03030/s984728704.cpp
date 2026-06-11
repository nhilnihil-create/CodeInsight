#include <math.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int N;
  cin >> N;
  vector<pair<pair<string, int>, int> > rs(N);

  rep(i, N) {
    cin >> rs[i].first.first >> rs[i].first.second;
    rs[i].first.second *= -1;
    rs[i].second = i + 1;
  }
  sort(rs.begin(), rs.end());

  for (const auto &r : rs) cout << r.second << endl;
}

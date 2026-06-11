#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int N; cin >> N;
  int x = 0, total = 0;
  for (int i = 0; i < N; ++i) {
    int A; cin >> A;
    if (x >= A) {
      x = A;
    } else {
      total += A - x;
      x = A;
    }
  }
  cout << total << endl;
}

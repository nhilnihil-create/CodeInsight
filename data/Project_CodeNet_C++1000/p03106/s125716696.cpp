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
  int A, B, K; cin >> A >> B >> K;
  vector<int> v;
  for (int i = 1; i <= min(A, B); ++i) {
    if (A % i == 0 && B % i == 0) v.push_back(i);
  }

  int N = v.size();
  cout << v[N-K] << endl;
}

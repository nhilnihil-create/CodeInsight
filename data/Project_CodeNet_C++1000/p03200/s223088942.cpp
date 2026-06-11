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
  string S; cin >> S;
  int N = S.size();
  LL cnt = 0;
  LL num_b = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'B') ++num_b;
    else             cnt += num_b;
  }
  cout << cnt << endl;
}

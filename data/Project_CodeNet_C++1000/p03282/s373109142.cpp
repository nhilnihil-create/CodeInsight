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
  int K; cin >> K;
  for (int i = 0; i < K; ++i) {
    if (S[i] != '1') {
      cout << S[i] << endl;
      return 0;
    }
  }
  cout << S[K-1] << endl;
}

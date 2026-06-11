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
  string S, T; cin >> S >> T;
  map<char, char> m1, m2;
  for (int i = 0; i < S.size(); ++i) {
    if (m1.count(S[i]) && m1[S[i]] != T[i]) {
      cout << "No" << endl;
      return 0;
    } else if (m2.count(T[i]) && m2[T[i]] != S[i]) {
      cout << "No" << endl;
      return 0;
    } else {
      m1[S[i]] = T[i];
      m2[T[i]] = S[i];
    }
  }
  cout << "Yes" << endl;
}

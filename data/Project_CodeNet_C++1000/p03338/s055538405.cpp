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
  string S; cin >> S;
  int vmax = 0;
  for (int i = 0; i < N; ++i) {
    set<char> ls, rs;
    for (int j = 0; j < i; ++j) {
      ls.insert(S[j]);
    }
    for (int j = i; j < N; ++j) {
      rs.insert(S[j]);
    }

    int cnt = 0;
    for (char l : ls) {
      for (char r : rs) {
        if (l == r) ++cnt;
      }
    }
    vmax = max(vmax, cnt);
  }
  cout << vmax << endl;
}

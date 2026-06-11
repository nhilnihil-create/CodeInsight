#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  string A = "";
  string B = "";

  for (int i = 0; i < N; ++i) {
    A += S[i];
    B += S[2 * N - i - 1];
  }

  map<string, map<string, int> > counter;

  for (int mask = 0; mask <= pow(2, N) - 1; ++mask) {
    string sa = "";
    string sb = "";

    for (int i = 0; i < N; ++i) {
      if ((mask >> i) & 1) {
        sa += A[i];
      } else {
        sb += A[i];
      }
    }

    ++counter[sa][sb];
  }

  ll ans = 0;

  for (int mask = 0; mask <= pow(2, N) - 1; ++mask) {
    string sa = "";
    string sb = "";

    for (int i = 0; i < N; ++i) {
      if ((mask >> i) & 1) {
        sa += B[i];
      } else {
        sb += B[i];
      }
    }

    ans += counter[sa][sb];
  }

  cout << ans << endl;

  return 0;
}

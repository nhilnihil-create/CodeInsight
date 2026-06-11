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

LL modpow(LL a, LL b) {
  LL r = 1;
  while (b) {
    if (b % 2 == 1) r = r * a % kMod;
    a = a * a % kMod;
    b /= 2;
  }
  return r;
}

int main() {
  string S; cin >> S;
  int rc = 0, rq = 0;
  for (char c : S) {
    if      (c == 'C') ++rc;
    else if (c == '?') ++rq;
  }

  LL ans = 0, la = 0, lq = 0;
  for (int i = 0; i < S.size(); ++i) {
    char c = S[i];
    if (c == '?') rq--;

    if (c == 'A') {
      ++la;
    } else if (c == 'B' || c == '?') {
      LL l = (la * modpow(3, lq) + lq * modpow(3, lq-1)) % kMod;
      LL r = (rc * modpow(3, rq) + rq * modpow(3, rq-1)) % kMod;
      ans = (ans + l * r) % kMod;
    } else if (c == 'C') {
      --rc;
    }

    if (c == '?') lq++;
  }

  cout << ans << endl;
}

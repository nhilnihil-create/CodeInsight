#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int mod = (int) 1e9 + 7;

long long binpow(long long x, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) {
      res = (res * x) % mod;
      p--;
    } else {
      x = (x * x) % mod;
      p /= 2;
    }
  }
  return res % mod;
}

long long inv(long long x) {
  return binpow(x, mod - 2) % mod;
}

int n;
string s;
int cntC, cntQ;
long long cntQQ, cntBC, cntBQ, cntQC;
long long ans;
long long totalQ;

int main() { 

  getline(cin, s);
  n = sz(s);

  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      totalQ++;
    }
  }

  for (int i = n - 1; i >= 0; i--) {

    if (s[i] == 'A') {
      ans = (ans + 1ll * cntQQ * binpow(3, totalQ - 2) % mod) % mod;
      ans = (ans + 1ll * cntBC * binpow(3, totalQ) % mod) % mod;
      ans = (ans + 1ll * cntBQ * binpow(3, totalQ - 1) % mod) % mod;
      ans = (ans + 1ll * cntQC * binpow(3, totalQ - 1) % mod) % mod;
    }
    if (s[i] == '?') {
      ans = (ans + 1ll * cntQQ * binpow(3, totalQ - 3) % mod) % mod;
      ans = (ans + 1ll * cntBC * binpow(3, totalQ - 1) % mod) % mod;
      ans = (ans + 1ll * cntBQ * binpow(3, totalQ - 2) % mod) % mod;
      ans = (ans + 1ll * cntQC * binpow(3, totalQ - 2) % mod) % mod;
    }

    if (s[i] == 'B') {
      cntBC += cntC;
      cntBQ += cntQ;
    }
    if (s[i] == '?') {
      cntQQ += cntQ;
      cntQC += cntC;
    }
    if (s[i] == '?') {
      cntQ++;
    } 
    if (s[i] == 'C') {
      cntC++;
    }
  }

  cout << ans << endl;

  return 0;
}

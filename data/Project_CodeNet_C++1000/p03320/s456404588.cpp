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

int k;
long long n = 1;
long long best = -1;
long long bestSum = 0;

int getSum(long long x) {
  int res = 0;
  while (x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main() { 

  cin >> k;

  while (k) {
    printf("%lld\n", n);
    k--;

    long long cur = n;
    long long p = 1;
    best = -1;
    for (int i = 0; i <= 17; i++) {
      int digit = cur % 10;
      for (int j = digit + 1; j <= 10; j++) {
        long long go = cur - digit + j;
        go = go * p + (p - 1);
        long long sum = getSum(go);
        if (best == -1 || (go * bestSum < sum * best || (go < best && go * bestSum == best * sum))) {
          best = go;
          bestSum = sum;
        }
      }
      p *= 10;
      if (cur == 0) {
        break;
      }
      cur /= 10;
    }

    n = best;
  }

  return 0;
}

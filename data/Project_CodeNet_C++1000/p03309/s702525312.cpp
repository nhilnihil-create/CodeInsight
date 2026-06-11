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

const int MAXN = 2 * 105000;

int n;
int a[MAXN];

long long f(long long b) {
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += abs(a[i] - (b + i + 1));
  }
  return res;
}

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // for (int i = -10; i <= 10; i++) {
  //   cerr << f(i) << endl;
  // }
  // return 0;

  long long l = -1e9, r = 1e9;
  while (r - l > 10) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    if (f(m1) > f(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }

  long long ans = f(l);
  for (long long i = l; i <= r; i++) {
    ans = min(ans, f(i));
  }

  cout << ans << endl;

  return 0;
}

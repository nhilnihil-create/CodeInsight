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

const int MAXN = 105000;

int n;
int a[MAXN];
long long l[MAXN], r[MAXN];

int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      l[i] = abs(a[i]);
    } else {
      l[i] = l[i - 1] + abs(a[i] - a[i - 1]);
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      r[i] = abs(a[i]);
    } else {
      r[i] = r[i + 1] + abs(a[i] - a[i + 1]);
    }
  }

  for (int i = 0; i < n; i++) {
    long long cur = 0;
    if (i == 0) {
      cur = r[i + 1] + abs(a[i + 1]);
    } else if (i == n - 1) {
      cur = l[i - 1] + abs(a[i - 1]);
    } else {
      cur = l[i - 1] + r[i + 1] + abs(a[i + 1] - a[i - 1]);
    }
    printf("%lld\n", cur);
  }

  return 0;
}

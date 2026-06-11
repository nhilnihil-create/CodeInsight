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
long long c;
long long x[MAXN];
int v[MAXN];
long long ans = 0;
long long l[MAXN], r[MAXN];
long long mxL[MAXN], mxR[MAXN];

int main() { 

  scanf("%d %lld", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%lld %d", &x[i], &v[i]);
  }

  long long cur = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cur -= x[i];
    } else {
      cur -= x[i] - x[i - 1];
    }
    cur += v[i];
    l[i] = cur;
    ans = max(ans, l[i]);
  }

  cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      cur -= c - x[i];
    } else {
      cur -= x[i + 1] - x[i];
    }
    cur += v[i];
    r[i] = cur;
    ans = max(ans, cur);
  }

  for (int i = 0; i < n; i++) {
    mxL[i] = l[i];
    if (i > 0) {
      mxL[i] = max(mxL[i - 1], mxL[i]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    mxR[i] = r[i];
    if (i + 1 < n) {
      mxR[i] = max(mxR[i + 1], mxR[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    long long cur = l[i];
    cur -= x[i];
    if (i + 1 < n) {
      cur += mxR[i + 1];
    }
    ans = max(ans, cur);
  }
  for (int i = n - 1; i >= 0; i--) {
    long long cur = r[i];
    cur -= c - x[i];
    if (i > 0) {
      cur += mxL[i - 1];
    }
    ans = max(ans, cur);
  }

  cout << ans << endl;

  return 0;
}

#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 1e9 + 7;

int add(int a, int b) {
  int c = a + b;
  if (c < 0) c += M;
  if (c >= M) c -= M;
  return c;
}

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

int inv(int x) {
  return pw(x, M - 2);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  vector <ll> pref;
  ll s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
    pref.push_back(s);
  }
  vector <int> cur(n + 1);
  cur[0] = inv(0);
  for (int i= 1; i <= n; i++) {
    cur[i] = inv(i);
    cur[i] = add(cur[i], cur[i - 1]);
  }
  auto sm = [&] (int l, int r) {
    return add(cur[r], -cur[l - 1]);
  };
  int x = 0;
  for (int i = 0; i < n; i++) {
    int ok = add(sm(1, i + 1), sm(1, n - i));
    ok = add(ok, -1);
    x = add(x, mul(ok, a[i]));
  }
  int ret = 1;
  for (int i = 1; i <= n; i++)ret=mul(ret,i);
  cout << mul(x, ret) << endl;
}

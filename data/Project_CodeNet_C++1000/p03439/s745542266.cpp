#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {

  int n;
  cin >> n;

  function<bool(int)> query = [&](int k) {
    cout << k << endl;
    string s;
    cin >> s;
    if (s == "Vacant")
      exit(0);
    return s == "Male";
  };
  int l = 0, r = n - 1;
  bool resl = query(l), resr = query(r);
  while (r - l > 2) {
    int mid = (l + r) >> 1;
    bool res = query(mid);
    if ((res ^ resl ^ mid ^ l) & 1) {
      r = mid;
      resr = res;
    } else {
      l = mid;
      resl = res;
    }
  }
  query((l + r) >> 1);

  return 0;
}

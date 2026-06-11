#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long llong;
const llong mod = 1000000000000037LL;
const llong base = 131;

struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
    val = _val % mod;
  }
};

modint operator+ (modint p, modint q) {
  return modint(p.val + q.val);
}

modint operator- (modint p) {
  return modint(mod - p.val);
}

modint operator- (modint p, modint q) {
  return p + (-q);
}

modint operator* (modint p, modint q) {
  return modint(p.val * q.val);
}

bool operator< (modint p, modint q) {
  return p.val < q.val;
}

modint operator== (modint p, modint q) {
  return p.val == q.val;
}

int length;
string str;
modint redhash (int mask) {
  int left = length;
  modint ans (0);
  for (int i = 0; i < length; i++) {
    if (mask & 1 << i) {
      left--;
      ans = ans * modint(base);
      ans = ans + modint(str[i]);
    }
  }
  for (int i = 0; i < left; i++) {
    ans = ans * modint(base);
  }
  return ans;
}

modint bluehash (int mask) {
  modint ans (0);
  for (int i = length - 1; i >= 0; i--) {
    if (!(mask & 1 << i)) {
      ans = ans * modint(base);
      ans = ans + modint(str[i]);
    }
  }
  return ans;
}

int main () {
  cin >> length >> str;

  map<modint, llong> cnt;
  for (int i = 0; i < 1 << length; i++) {
    modint hashd = redhash(i) - bluehash(i);
    if (cnt.count(hashd) == 0) {
      cnt[hashd] = 0;
    }
    cnt[hashd]++;
  }

  reverse(str.begin(), str.end());

  llong ans = 0;
  for (int i = 0; i < 1 << length; i++) {
    modint cur = redhash(i) - bluehash(i);
    if (cnt.count(cur) != 0) {
      ans += cnt[cur];
    }
  }

  cout << ans << endl;
}

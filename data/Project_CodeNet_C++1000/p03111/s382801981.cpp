#include <bits/stdc++.h>
typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;

#define MAX_NUM (1000000007)
#define PI 3.14159265358979323846

using namespace std;

template <typename T>
static inline void ArrayInput(vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cin >> *itr;
}

template <typename T>
static inline void ArrayPut(const vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cout << *itr << " ";
  cout << endl;
}

template <typename T>
static inline T ArraySum(vector<T>& A) {
  T res = 0;
  for (auto itr = A.begin(); itr < A.end(); ++itr) res += *itr;
  return res;
}

bool Sec_compare(pair<uint64_t, uint64_t> a, pair<uint64_t, uint64_t> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

u64 dec_dig(u64 num) {
  u64 res = 0;
  while (num > 0) {
    num /= 10;
    ++res;
  }
  return res;
}

i64 modinv(i64 a, i64 m) {
  i64 b = m, u = 1, v = 0;
  while (b) {
    i64 t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

u64 gcd(u64 a, u64 b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

i64 My_Comb(u64 n, u64 k, i64 m) {
  if (n < k) return 0;
  if (k == 0 || n == k) return 1;
  u64 res = 1;
  k = (n / 2 < k) ? n - k : k;
  for (u64 i = 1; i <= k; ++i)
    res = (((res * (n + 1 - i)) % m) * modinv(i, m)) % m;
  return res;
}

i64 My_Pow(u64 a, u64 n, i64 m) {
  u64 tmp = n, calc = 1;
  while (tmp > 0) {
    if (tmp % 2) {
      tmp--;
      calc *= a;
      calc %= m;
    } else {
      a *= a;
      a %= m;
      tmp /= 2;
    }
  }
  return calc;
}

class UnionFind {
 public:
  vector<u64> Par;
  vector<u64> sz;

  UnionFind(u64 n);
  u64 root(u64 x);
  bool same(u64 x, u64 y);
  void unite(u64 x, u64 y);
  u64 size(u64 x);
};

UnionFind::UnionFind(u64 n) {
  Par.resize(n);
  sz.assign(n, 1);
  for (u64 i = 0; i < n; ++i) Par[i] = i;
}

u64 UnionFind::root(u64 x) {
  if (Par[x] == x) {
    return x;
  } else {
    return Par[x] = root(Par[x]);
  }
}

bool UnionFind::same(u64 x, u64 y) { return root(x) == root(y); }

u64 UnionFind::size(u64 x) { return sz[root(x)]; }

void UnionFind::unite(u64 x, u64 y) {
  x = root(x);
  y = root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  Par[y] = x;
}

int main() {
  cout << setprecision(18);
  i32 N, Tar[3];
  cin >> N >> Tar[0] >> Tar[1] >> Tar[2];
  vector<i32> l(N);
  ArrayInput(l);
  vector<pair<set<u32>, u32>> Bamboo[3];
  u32 bit_pattern = My_Pow(2, N, MAX_NUM);
  for (u32 i = 1; i < bit_pattern; ++i) {
    i32 cost[3] = {0, 0, 0};
    i32 tmp = 0;
    i32 calc = -10;
    set<u32> s;
    for (u32 k = 0; k < N; ++k) {
      if ((i >> k) & 0x01) {
        tmp += l[k];
        s.insert(k);
        calc += 10;
      }
    }
    if (N - s.size() < 2) continue;
    for (u32 k = 0; k < 3; ++k) {
      cost[k] = calc;
      cost[k] += abs(Tar[k] - tmp);
      Bamboo[k].push_back(make_pair(s, cost[k]));
    }
  }
  u32 res = MAX_NUM;
  for (auto itrA = Bamboo[0].begin(); itrA != Bamboo[0].end(); ++itrA) {
    set<u32> sa = itrA->first;
    if (itrA->second > res) continue;
    for (auto itrB = Bamboo[1].begin(); itrB != Bamboo[1].end(); ++itrB) {
      bool flag = true;
      set<u32> sb = itrB->first;
      for (auto si = sa.begin(); si != sa.end(); ++si) {
        if (sb.find(*si) != sb.end()) {
          flag = false;
          break;
        }
        sb.insert(*si);
      }
      if (!flag) continue;
      u32 tmp = itrA->second + itrB->second;
      if (tmp > res) continue;
      for (auto itrC = Bamboo[2].begin(); itrC != Bamboo[2].end(); ++itrC) {
        flag = true;
        for (auto si = sb.begin(); si != sb.end(); ++si) {
          if (itrC->first.find(*si) != itrC->first.end()) {
            flag = false;
            break;
          }
        }
        if (flag) {
          if (tmp + itrC->second < res) res = tmp + itrC->second;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}

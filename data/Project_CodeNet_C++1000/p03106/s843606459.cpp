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

int main() {
  cout << setprecision(18);
  i64 A, B, K;
  cin >> A >> B >> K;

  vector<u32> res;

  for (u32 i = 100; i >= 1; --i) {
    if (A % i == 0 && B % i == 0) {
      res.push_back(i);
    }
  }

  cout << res[K - 1] << endl;

  return 0;
}

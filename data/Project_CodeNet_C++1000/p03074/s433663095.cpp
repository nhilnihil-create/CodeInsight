#include <bits/stdc++.h>

#define MAX_NUM (1000000000 + 7)

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;

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

u64 gcd(u64 a, u64 b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

int main() {
  cout << setprecision(18);
  u32 N, K;
  string S;
  cin >> N >> K >> S;

  vector<pair<u32, u32>> Zeros;
  u32 L = 0, R = 0;

  bool flag = false;
  for (u32 i = 0; i < N; ++i) {
    if (S[i] == '0') {
      if (!flag) L = i;
      flag = true;
    } else {
      if (flag) {
        R = i - 1;
        Zeros.push_back(make_pair(L, R));
        flag = false;
      }
    }
  }
  if (flag) Zeros.push_back(make_pair(L, N - 1));

  if (K >= Zeros.size())
    cout << N << endl;
  else {
    if (Zeros[0].first != 0) L = 0;
    u32 res = 0;
    for (u32 i = 0; i + K <= Zeros.size(); ++i) {
      u32 tmp;
      L = (i != 0) ? Zeros[i - 1].second + 1 : 0;
      R = (i + K != Zeros.size()) ? Zeros[i + K].first - 1 : N - 1;

      tmp = R - L + 1;
      if (res < tmp) res = tmp;
    }
    cout << res << endl;
  }

  return 0;
}

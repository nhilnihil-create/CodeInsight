/*
m 个数的集合的中位数定义成将集合升序排序之后得到的数组中下标(从 0 开始)为
floor(m/2) 的数.

求所有连续子串的中位数的中位数.

对一个含有 n 个数的集合, x 如果是它的中位数, 等价于:

1. <= x 的数至少有 floor(n/2) 个;
2. x 是满足 1 的数中最小的.

如果一个子串长度是 l, 那么至少有 floor(l/2) 个数 <= 其中位数; 又假设这个中位数 <=
x, 那么就有 floor(l/2) 个数 <= x.

<= x 者设为 n1 个, > x 者设为 n2 个:

  n1 >= floor(l/2)
  n2 <= l-floor(l/2) = ceil(l/2)
  n2 - n1 <= ceil(l/2) - floor(l/2) = l % 2

当 l % 2 == 0, 要求  >= 0.

当 l % 2 == 1, 要求 n1-n2 >= 1, 但是 n1-n2 = 0 的情况是不可能存在的(否则
l=n1+n2 是偶数), 所以也等价于 n1-n2 >= 0.

于是对 >= x 者取 f[] 为 1, 对 < x 者取 -1, 数列中位数 >= x 等价于 f[] 的和 >= 0.

设 sum[i] 是 f[0] + f[1] + ... + f[i-1], sum[0] 设为 0.

每个 sum[j]-sum[i] (0 <= i < j <= n) 都对应一个子串的 f 的和. 每个和只要 >= 0
则说明有一个子串的中位数 >= x. 即要判断其个数是否是 >= ceil(子串数 / 2) 的.

sum[j]-sum[i] >= 0, 意味着 sum[j] >= sum[i], 也就是要在 sum 数组上统计逆序数.
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long llong;

constexpr int kMaxN = 1e5 + 10;

template <typename T>
void CopyN(T* dst, T* src, int n) {
  if (n <= 0) {
    return;
  }
  memcpy(dst, src, sizeof(T) * n);
}

llong MergeSort(int a[], int n, int aux[]) {
  llong cnt = 0;
  for (int d = 1; d <= n; d <<= 1) {
    int d2 = (d << 1);
    for (int l = 0; l < n; l += d2) {
      int m = std::min(l + d, n);
      int r = std::min(m + d, n);

      int w = l;
      int u = l;
      int v = m;

      while (u < m && v < r) {
        if (a[u] <= a[v]) {
          aux[w++] = a[u++];
          cnt += r - v;
        } else {
          aux[w++] = a[v++];
        }
      }

      CopyN(aux + w, a + u, m - u);
      CopyN(aux + w, a + v, r - v);
    }
    CopyN(a, aux, n);
  }
  return cnt;
}

llong Count(int a[], int n, int mid) {
  static int sum[kMaxN];
  static int aux[kMaxN];

  sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + (a[i] >= mid ? 1 : -1);
  }

  return MergeSort(sum, n + 1, aux);
}

int main() {
  int n;
  scanf("%d", &n);

  static int a[kMaxN];
  int maxa = 10;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    maxa = std::max(maxa, a[i]);
  }

  llong total = static_cast<llong>(n) * (n + 1) / 2;
  llong total2 = (total + 1) / 2;
  int low = 0;
  int upp = maxa + 10;

  while (upp - low > 1) {
    int mid = (low + upp) / 2;
    if (Count(a, n, mid) >= total2) {
      low = mid;
    } else {
      upp = mid;
    }
  }

  printf("%d\n", low);
  return 0;
}

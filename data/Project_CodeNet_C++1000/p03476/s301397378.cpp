#include <cstdio>
#include <cmath>
 
#define MAX 100000

bool prime[MAX + 1];
int count[MAX + 1];
int N, L, R;

int main() {
  // 素数配列をエラトステネスの篩を使って生成
  // 素数であれば false, 素数でなければ true
  for (int i = 2; i < sqrt(MAX); ++ i)
    if (!prime[i])
      for (int j = i + i; j <= MAX; j += i)
        prime[j] = true;

  // N と (N + 1) / 2 が素数である要素配列を生成
  // 条件が成立すれば 1、成立しなければ 0
  for (int i = 3; i <= MAX; i += 2)
    if (!prime[i] && !prime[(i + 1) >> 1])
      count[i] = 1;

  // 累積和を生成
  for (int i = 3; i <= MAX; ++ i)
    count[i] += count[i - 1];

  scanf("%d", &N);
  while (N --) {
    scanf("%d%d", &L, &R);
    printf("%d\n", count[R] - count[L - 1]);
  }

  return 0;
}

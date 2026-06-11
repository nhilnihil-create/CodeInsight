#include <cstdio>
#include <bitset>

using namespace std;

int a[2043];
bitset<4000043> dp;

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int sum = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    dp |= dp << a[i];
  }
  for (int i = (sum + 1) / 2; i <= sum; ++i) {
    if (dp[i] == 1) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long f(int a, int x) {
  return 1LL * x * a - 1LL * x * x;
}

long long calc(int a, int s) {
  return max(f(a, min(s, a / 2)), f(a, min(s, (a + 1) / 2)));
}

int get(int a, int b) {
  int l = 0, r = a;
  while (r - l > 1) {
    int s = (l + r) / 2;
    if (calc(b + s + 1, s) < 1LL * a * b) {
      l = s;
    } else {
      r = s;
    }
  }
  return l;
}

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int va = get(a, b);
    int vb = get(b, a);
    printf("%d\n", va + vb + min(a - 1 - va, b - 1 - vb));
  }
}

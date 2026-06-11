#include <cstdio>

template<typename T> void inline fastin(T &num) {
  T c;
  num = 0;
  c = getchar_unlocked();
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
}

int main() {
  int a, b, c; fastin(a); fastin(b); fastin(c);
  if (a + b >= c) {
    printf("%s\n", "Yes");
  } else {
    printf("%s\n", "No");
  }
  return 0;
}

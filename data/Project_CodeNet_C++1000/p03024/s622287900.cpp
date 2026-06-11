#include <cstdio>

int main()
{
  char ch = ' ';
  int cnt = 0;
  while (ch != '\n') {
    ch = getchar();
    if (ch == 'x') {
      cnt++;
    }
  }
  if (8 <= cnt) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}

#include <cstdio>

constexpr unsigned int m = 1000000007;
int main()
{
  char st[100001];
  scanf("%s", st);
  unsigned int s[4] = {1, 0, 0, 0};
  for (char *p = st; *p; ++p)
  {
    switch (*p)
    {
      case 'A':
        s[1] = (s[1] + s[0]) % m;
        break;
      case 'B':
        s[2] = (s[2] + s[1]) % m;
        break;
      case 'C':
        s[3] = (s[3] + s[2]) % m;
        break;
      default:
        s[3] = (3 * s[3] + s[2]) % m;
        s[2] = (3 * s[2] + s[1]) % m;
        s[1] = (3 * s[1] + s[0]) % m;
        s[0] = 3 * s[0] % m;
        break;
    }
  }
  printf("%u\n", s[3]);
  return 0;
}
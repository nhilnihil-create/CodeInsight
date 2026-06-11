#include <cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  char s[10];
  puts("0"); fflush(stdout);
  scanf("%s", s);
  if (*s == 'V') return 0;
  char first = *s;
  int l = 0, r = n;
  while (r - l > 1)
  {
    int mid = l + (r - l) / 2;
    printf("%d\n", mid); fflush(stdout);
    scanf("%s", s);
    if (*s == 'V') return 0;
    if ((mid & 1) != (l & 1))
    {
      if (*s != first) { l = mid; first = *s; }
      else r = mid;
    }
    else
    {
      if (*s == first) l = mid;
      else r = mid;
    }
  }
  printf("%d\n", r); fflush(stdout);
  scanf("%s", s);
  if (*s == 'V') return 0;
}

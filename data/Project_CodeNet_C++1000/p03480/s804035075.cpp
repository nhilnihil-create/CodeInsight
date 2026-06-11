#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;
char lx[N];

int main() {
  scanf("%s", lx + 1);
  int n = strlen(lx + 1);
  for(int i = 1; i <= n; ++i)
    a[i] = (lx[i] == '1');
  if(n & 1) {
    int mid = n / 2 + 1, pd = a[mid], tmp = mid;
    for(int i = mid; i <= n; ++i)
      if(a[i] == pd) tmp = i;
      else break;
    int pos = mid;
    for(int i = mid - 1; i >= 1; --i)
      if(a[i] == pd) pos = i;
      else break;
    printf("%d\n", mid + max(0, min(tmp - mid, mid - pos)));
  } else {
    int mid = n / 2, pd = a[mid];
    if(a[mid] != a[mid + 1]) printf("%d\n", n / 2);
    else {
      int tmp = mid + 1;
      for(int i = mid + 1; i <= n; ++i)
        if(a[i] == pd) tmp = i;
        else break;
      int pos = mid;
      for(int i = mid - 1; i >= 1; --i)
        if(a[i] == pd) pos = i;
        else break;
      printf("%d\n", mid + max(0, min(tmp - mid, mid - pos + 1)));
    } 
  }
  return 0;
}
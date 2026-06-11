#include <bits/stdc++.h>
using namespace std;

int n, mx;
int a[200005];
map<int, int> mp;

bool check(int lmt) {
  mp.clear();
  int now = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > now) now = a[i];
    else {
      now = a[i];
      while (!mp.empty()) {
        int last = (--mp.end())->first;
        if (last >= now) mp.erase(last);
        else break;
      }
      int nnow = now - 1;
      mp[nnow]++;
      while (nnow >= 0 && mp[nnow] >= lmt) {
        mp.erase(nnow);
        --nnow;
        mp[nnow]++;
      }
      if (nnow < 0) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  bool flag = true;
  for (int i = 1; i <= n; ++i)
    flag &= (a[i] > a[i - 1]);
  if (flag) return puts("1") & 0;
  mx = *max_element(a + 1, a + n + 1);
  int l = 2, r = n, ans = n;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}

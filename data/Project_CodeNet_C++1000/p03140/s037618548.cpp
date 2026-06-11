#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

const int N = 123;

char a[N], b[N], c[N];

int calc(int idx) {
  map<char,int> mp;
  mp[a[idx]]++;
  mp[b[idx]]++;
  mp[c[idx]]++;
  int mx = -1;
  for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++) {
    mx = max(mx, it->second);
  }
  return 3 - mx;
}

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s %s %s", a, b, c);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += calc(i);
  }
  printf("%d\n", ans);
  return 0;
}
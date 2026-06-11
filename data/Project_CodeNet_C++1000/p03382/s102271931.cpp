#include <bits/stdc++.h>

using namespace std;

int v[100002];
int n, maxx, sol;

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    maxx = max(maxx, v[i]);
  }
  int p = 1;
  while (v[p] != maxx)
    p++;
  v[p] = -1;
  int nr1, nr2;
  if (maxx & 1)
    nr1 = maxx / 2, nr2 = maxx / 2 + 1;
  else
    nr1 = nr2 = maxx / 2;
  int dist = maxx + 2;
  for (int i = 1; i <= n; i++) {
    if (v[i] != -1) {
      int t = min(abs(v[i] - nr1), abs(v[i] - nr2));
      if (dist > t) {
        dist = t;
        sol = v[i];
      }
    }
  }
  cout << maxx << " " << sol;
  return 0;
}

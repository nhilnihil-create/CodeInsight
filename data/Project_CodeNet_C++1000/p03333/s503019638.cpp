#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n;
int l[MAX_N+1], r[MAX_N+1];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  l[n] = r[n] = 0;

  sort(l, l+n+1, greater<int>());
  sort(r, r+n+1);

  uint64_t d = 0;
  for (int i = 0; i < n && l[i] > r[i]; i++)
    d += (l[i] - r[i]) * 2;

  cout << d << endl;

  return 0;
}

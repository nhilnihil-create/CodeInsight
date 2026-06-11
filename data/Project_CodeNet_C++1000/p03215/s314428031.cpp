#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  vector<ll> at(n+1); at[0] = 0;
  for (int i = 1; i < n+1; ++i) at[i] = at[i-1] + a[i-1];
  
  int m = n*(n+1)/2;
  vector<ll> b(m);
  int idx = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n+1; ++j)
      b[idx++] = at[j] - at[i];
  
  vector<bool> cand(m, true);
  ll dig = 1ll << 39;
  ll max_a = 0;
  while (dig)
  {
    int count = 0;
    for (int i = 0; i < m; ++i)
      if (cand[i] && dig & b[i]) ++count;
    if (count >= k)
    {
      max_a |= dig;
      for (int i = 0; i < m; ++i)
        if (!(dig & b[i])) cand[i] = false;
    }
    
    dig >>= 1;
  }
  
  cout << max_a << endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
vector<int> a, h;
vector<ll> bit;

void update(int i, ll v)
{
  while (i <= n)
  {
    bit[i] = max(bit[i], v);
    i += i & -i;
  }
}

ll query(int i)
{
  i -= 1;
  ll ret = 0;
  while (i > 0)
  {
    ret = max(ret, bit[i]);
    i -= i & -i;
  }
  return ret;
}

int main()
{
  cin >> n;
  h.resize(n);
  a.resize(n);
  rep(i, n)
    cin >> h[i];
  rep(i, n)
    cin >> a[i];
  bit.resize(n + 1);
  rep(i, n)
    update(h[i], query(h[i]) + a[i]);
  cout << query(n + 1) << endl;
  return 0;
}
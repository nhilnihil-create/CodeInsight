#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

// mode=true:RangeMinimumQuery
// mode=false:RangeMaximumQuery
template <typename T>
struct RMQ
{
  T INF;
  bool mode;
  int n;
  vector<T> dat;
  RMQ(int n_, bool minimum)
  {
    mode = minimum;
    if (mode)
      INF = numeric_limits<T>::max();
    else
      INF = numeric_limits<T>::min();
    n = 1;
    while (n < n_)
      n *= 2;
    dat.resize(n * 2 - 1);
    fill(dat.begin(), dat.end(), INF);
  }

  void update(int i, T x)
  {
    i += n - 1;
    dat[i] = x;
    while (i > 0)
    {
      i = (i - 1) / 2;
      if (mode)
        dat[i] = min(dat[i*2+1], dat[i*2+2]);
      else
        dat[i] = max(dat[i*2+1], dat[i*2+2]);
    }
  }

  T query(int a, int b, int k=0, int l=0, int r=-1)
  {
    if (r == -1)
      r = n;
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return dat[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    if (mode)
      return min(vl, vr);
    else
      return max(vl, vr);
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> h(n), a(n);
  rep(i, n)
    cin >> h[i];
  rep(i, n)
    cin >> a[i];
  RMQ<ll> s(n + 1, false);
  s.update(0, 0);
  rep(i, n)
    s.update(h[i], s.query(0, h[i]) + a[i]);
  cout << s.query(0, n + 2) << endl;
  return 0;
}
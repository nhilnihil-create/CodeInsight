#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

struct TTree {
  vector<ll> t;
  ll n;
  
  void init (ll nn)
  {
      n = nn;
        t.assign (n, 0);
  }
  
  ll sum (ll r)
  {
      ll result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
              result += t[r];
          return result;
  }
  
  void inc (ll i, ll delta)
  {
      for (; i < n; i = (i | (i+1)))
            t[i] += delta;
  }
  
  ll sum (ll l, ll r)
  {
      return sum (r) - sum (l-1);
  }
  
  void init (vector<ll> a)
  {
      init ((ll) a.size());
        for (unsigned i = 0; i < a.size(); i++)
              inc (i, a[i]);
  }
};

ll NumInversions(vector<ll> a) {
  ll result = 0;
//  for (int l = 0; l < a.size(); ++l) {
//    for (int r = l + 1; r < a.size(); ++r) {
//      if (a[l] <= a[r]) result++;
//    }
//  }
  ll mi = *min_element(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i) {
    a[i] -= mi;
  }
  ll ma = *max_element(a.begin(), a.end());
  TTree tree;
  tree.init(ma + 1);
  for (ll x : a) {
    result += tree.sum(0, x);
    tree.inc(x, 1);
  }
  return result;
}



int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll l = 0;
  ll r = 1000 * 1000 * 1000 + 1;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    vector<ll> A(n + 1);
    for (int i = 0; i < n; ++i) {
      A[i + 1] = a[i] >= m;
      A[i + 1] += A[i];
    }
    for (int i = 0; i <= n; ++i) {
      A[i] = 2 * A[i] - i;
    }
    if (NumInversions(A) * 2 >= n * (n + 1) / 2) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}

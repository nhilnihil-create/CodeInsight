#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

#define INF 1000000000000000000LL
using ll = long long int;
int n;
std::vector<ll> a;
std::vector<ll> b;

ll sum(int from, int until)
{
  return b[until] - b[from];
}

int search(int from, int until)
{
  int l = from; // dummy
  ll tmp = INF;
  for (int i = from + 1; i <= until - 1; i++) {
    ll diff = abs(sum(from, i) - sum(i, until));
    if (diff < tmp) {
      l = i;
      tmp = diff;
    }
  }

  return l;
}

int bs(int from, int until)
{
  int index = from; // dummy
  ll mini = INF;

  int l = from + 1;
  int r = until;

  while (l < r) {
    int mid = l + (r - l) / 2;
    ll det = sum(from, mid) - sum(mid, until);

    if (abs(det) < mini) {
      index = mid;
      mini = abs(det);
    } 

    if (det > 0) { // 前の方が大きい
      r = mid;
    } else if (det < 0) {
      l = mid + 1;
    } else {
      break;
    }
  }

  return index;
}


int main()
{
  using namespace std;

  cin >> n;
  a.reserve(n);
  b.reserve(n+1);

  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> a[i];
  }

  b.push_back(0);
  ll accum = 0;
  for (int i = 0; i < n; i++) {
    accum += a[i];
    b[i+1] = accum;
  }

  ll minimum = INF;
  for (int c = 2; c <= n - 2; c++) {
    int l = bs(0, c);
    int r = bs(c, n);

    ll mn = min(sum(0, l), min(sum(l, c), min(sum(c, r), sum(r, n))));
    ll mx = max(sum(0, l), max(sum(l, c), max(sum(c, r), sum(r, n))));

    minimum = min(minimum, mx - mn);
  }

  cout << minimum << endl;

  return 0;
}
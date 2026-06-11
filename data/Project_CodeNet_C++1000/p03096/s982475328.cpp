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
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MODULO = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vll c, w;
  int curColor = -1;
  int curW = 0;
  for (int i = 0; i < n; ++i) {
    int color;
    cin >> color;
    if (color == curColor) {
      //curW++;
      continue;
    }
    if (curW > 0) {
      c.push_back(curColor);
      w.push_back(curW);
    }
    curColor = color;
    curW = 1;
  }
  if (curW > 0) {
    c.push_back(curColor);
    w.push_back(curW);
  }
  n = c.size();
  vi last(3e5, n);
  vll a(n + 1);
  vll sum(n + 1);
  a[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (last[c[i]] < n) sum[i] = (sum[last[c[i]]] + w[last[c[i]]] * a[last[c[i]] + 1]) % MODULO;
    a[i] = (a[i + 1] + w[i] * sum[i]) % MODULO;
    last[c[i]] = i;
  }

  cout << a[0] << endl;

  return 0;
}

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
typedef pair<int, int> ii;

ii ma[19][1 << 18];

void Update(ii& a, int x) {
  if (x > a.first) {
    a.second = a.first;
    a.first = x;
  } else if (x > a.second) {
    a.second = x;
  }
}

ii Join(ii a, ii b) {
  Update(a, b.first);
  Update(a, b.second);
  return a;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (int i = 0; i < a.size(); ++i) cin >> a[i];

  for (int i = 0; i < (1 << n); ++i) ma[0][i].first = a[i];  

  for (int b = 1; b <= n; ++ b) {
    int r = n - b;
    for (int i = 0; i < (1 << r); ++i) {
      ma[b][i] = Join(ma[b - 1][i * 2], ma[b - 1][i * 2 + 1]);
    }
  }

  for (int b = 0; b < n; ++b) {
    for (int i = 0; i < n; ++i) for (int mask = 0; mask < (1 << n); ++ mask) {
      if (mask & (1 << i)) {
        ma[b][mask] = Join(ma[b][mask], ma[b][mask ^ (1 << i)]);
      }
    }          
  }

  for (int k = 1; k < (1 << n); ++k) {
    ii p = ma[0][k];
    int result = p.first + p.second;
    for (int b = 0; b < n; ++b) {
      int x = k >> b;
      if (x & 1) {
        x--;
        ii p = ma[b][x];
        result = max(result, p.first + p.second);
      }
    }
    cout << result << endl;
  }

  return 0;
}

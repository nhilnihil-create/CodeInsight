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

ii ma[1 << 18];

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

int GetValue(ii a) {
  return a.first + a.second;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (int i = 0; i < a.size(); ++i) cin >> a[i];

  for (int i = 0; i < (1 << n); ++i) ma[i].first = a[i];  

  for (int i = 0; i < n; ++i) for (int mask = 0; mask < (1 << n); ++mask) {
    if (mask & (1 << i)) {
      ma[mask] = Join(ma[mask], ma[mask ^ (1 << i)]);
    }
  }          

  int result = 0;
  for (int k = 1; k < (1 << n); ++k) {
    result = max(result, GetValue(ma[k]));
    cout << result << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<int> vodd(100001, 0), veven(100001, 0);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (i % 2 == 0)
      veven[v]++;
    else
      vodd[v]++;
  }

  auto even_max_pos = 1;
  auto even_2nd_pos = 0;
  auto odd_max_pos = 1;
  auto odd_2nd_pos = 0;

  auto fn = [](int& imax, int& i2ndmax, const vector<int>& v) {
    for (size_t i = 2; i < v.size(); i++) {
      if (v[imax] <= v[i]) {
        i2ndmax = imax;
        imax = i;
      } else if (v[i2ndmax] <= v[i]) {
        i2ndmax = i;
      }
    }
  };

  fn(even_max_pos, even_2nd_pos, veven);
  fn(odd_max_pos, odd_2nd_pos, vodd);

  if (even_max_pos != odd_max_pos) {
    cout << n - veven[even_max_pos] - vodd[odd_max_pos] << endl;
  } else {
    cout << min(n - veven[even_max_pos] - vodd[odd_2nd_pos],
                n - veven[even_2nd_pos] - vodd[odd_max_pos])
         << endl;
  }
}

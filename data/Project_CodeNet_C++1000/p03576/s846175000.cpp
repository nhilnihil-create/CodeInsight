#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;

  ll x, y;
  ll x_vertex[N];
  ll y_vertex[N];
  vector<ll> x_coords;
  vector<ll> y_coords;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;

    x_vertex[i] = x;
    y_vertex[i] = y;

    x_coords.push_back(x);
    y_coords.push_back(y);
  }

  sort(x_coords.begin(), x_coords.end());
  sort(y_coords.begin(), y_coords.end());

  ll ans = (x_coords[N - 1] - x_coords[0]) * (y_coords[N - 1] - y_coords[0]);

  for (int i = 0; i < N - 1; ++i) {
    ll x1 = x_coords[i];

    for (int j = i + 1; j < N; ++j) {
      ll x2 = x_coords[j];

      for (int k = 0; k < N - 1; ++k) {
        ll y1 = y_coords[k];

        for (int l = k + 1; l < N; ++l) {
          ll y2 = y_coords[l];

          int cnt = 0;

          for (int n = 0; n < N; ++n) {
            if (x_vertex[n] < x1 || x2 < x_vertex[n]) continue;
            if (y_vertex[n] < y1 || y2 < y_vertex[n]) continue;

            ++cnt;
          }

          ll area = abs(x2 - x1) * abs(y2 - y1);

          if (cnt >= K && ans > area) {
            ans = area;
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}

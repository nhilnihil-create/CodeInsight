#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> x(N), y(N);
  vector<ll> xarray, yarray;
  for (ll i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    xarray.push_back(x[i]);
    yarray.push_back(y[i]);
  }
  sort(xarray.begin(), xarray.end());
  sort(yarray.begin(), yarray.end());

  ll ans = (xarray[N - 1] - xarray[0]) * (yarray[N - 1] - yarray[0]);

  for (ll xi = 0; xi < N; xi++) {
    for (ll xj = xi + 1; xj < N; xj++) {
      for (ll yi = 0; yi < N; yi++) {
        for (ll yj = yi + 1; yj < N; yj++) {
          ll lx = xarray[xi], rx = xarray[xj];
          ll ly = yarray[yi], ry = yarray[yj];

          ll count = 0;
          for (ll i = 0; i < N; i++) {
            if (lx <= x[i] && x[i] <= rx && ly <= y[i] && y[i] <= ry) {
              count++;
            }
          }
          if (count >= K)
            ans = min(ans, abs(rx - lx) * abs(ry - ly));
        }
      }
    }
  }
  cout << ans << endl;
}
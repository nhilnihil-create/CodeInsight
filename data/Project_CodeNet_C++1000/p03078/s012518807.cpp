#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> xlist(x);
  for (int i = 0; i < x; i++) {
    cin >> xlist[i];
  }
  vector<ll> ylist(y);
  for (int i = 0; i < y; i++) {
    cin >> ylist[i];
  }
  vector<ll> zlist(z);
  for (int i = 0; i < z; i++) {
    cin >> zlist[i];
  }

  vector<ll> xylist(x * y);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      xylist[y * i + j] = xlist[i] + ylist[j];
    }
  }
  sort(xylist.begin(), xylist.end(), greater<ll>());

  int cnt = min(k, x * y);
  vector<ll> xyzlist(cnt * z);
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < z; j++) {
      xyzlist[z * i + j] = xylist[i] + zlist[j];
    }
  }

  sort(xyzlist.begin(), xyzlist.end(), greater<ll>());
  for (int i = 0; i < k; i++) {
    cout << xyzlist[i] << endl;
  }
  return 0;
}
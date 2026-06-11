#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

int main() {
  ll N;
  cin >> N;

  vi X(N), Y(N);
  for (ll i = 0; i < N; i++) cin >> X[i] >> Y[i];

  for (ll i = 0; i < N - 1; i++) {
    if ((X[i] + Y[i] + X[i + 1] + Y[i + 1]) % 2 != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  bool flag = false;

  if ((X[0] + Y[0]) % 2 == 0) {
    flag = true;
  }

  ll m = 31;

  if (flag) {
    cout << m + 1 << endl;
    cout << 1;
    for (ll i = 0; i < m; i++) {
      cout << ' ' << (1ll << i);
    }
    cout << endl;

    for (ll i = 0; i < N; i++) {
      X[i] -= 1;
    }
  } else {
    cout << m << endl;
    for (ll i = 0; i < m; i++) {
      if (i > 0) {
        cout << ' ';
      }

      cout << (1ll << i);
    }
    cout << endl;
  }

  for (ll i = 0; i < N; i++) {
    ll x = X[i], y = Y[i];
    ll u = x + y, v = x - y;
    vi v1(m, 1), v2(m, 1);

    {
      ll k = (1ll << m) - 1 - u;
      for (ll j = m - 1; j >= 0; j--) {
        if (k >= (1ll << j) * 2) {
          k -= (1ll << j) * 2;
          v1[j] = -1;
        }
      }
    }

    {
      ll k = (1ll << m) - 1 - v;
      for (ll j = m - 1; j >= 0; j--) {
        if (k >= (1ll << j) * 2) {
          k -= (1ll << j) * 2;
          v2[j] = -1;
        }
      }
    }

    string s;

    if (flag) {
      s += 'R';
    }

    for (ll j = 0; j < m; j++) {
      if (v1[j] == 1) {
        if (v2[j] == 1) {
          s += 'R';
        } else {
          s += 'U';
        }
      } else {
        if (v2[j] == 1) {
          s += 'D';
        } else {
          s += 'L';
        }
      }
    }

    cout << s << endl;
  }
}

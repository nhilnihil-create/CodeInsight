#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double pi = 3.14159265358979323846;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define MOD 1000000007LL
#define PS(p) cout << setprecision(15) << fixed << p << endl;
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
#define ALL(c) c.begin(), c.end()
#define MP(v) make_pair(v)
#define F first
#define S second

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, c;
  cin >> a;

  if (a == 1) {
    cout << "Hello World" << endl;
  } else {
    cin >> b >> c;
    cout << b + c << "\n";
  }

  return 0;
}

#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  ll d;
  map<ll, int> D;
  REP(i, N) {
    cin >> d;
    if (D.find(d) == D.end()) {
      D.insert(make_pair(d, 1));
    } else {
      ++D.at(d);
    }
  }

  int M;
  cin >> M;
  ll t;
  REP(i, M) {
    cin >> t;
    if (D.find(t) == D.end()) {
      cout << "NO" << endl;
      return 0;
    }

    if (D.at(t) == 0) {
      cout << "NO" << endl;
      return 0;
    }

    --D.at(t);
  }

  cout << "YES" << endl;

  return 0;
}

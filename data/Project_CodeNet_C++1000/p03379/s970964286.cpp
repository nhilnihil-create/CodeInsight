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
  vector<pair<ll, ll>> X;
  ll x;
  REP(i, N) {
    cin >> x;
    X.push_back(make_pair(x, i));
  }
  sort(X.begin(), X.end());

  int middle = N / 2;
  vector<ll> B(N);

  ll median;
  REP(i, N) {
    if (i == middle) {
      --middle;
    }

    median = X.at(middle).first;
    B.at(X.at(i).second) = median;
  }

  REP(i, N) { cout << B.at(i) << endl; }

  return 0;
}

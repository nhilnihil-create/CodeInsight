#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N;
  cin >> N;

  ll k = 2;
  while (k < 2000) {
    if (k * (k - 1) == N * 2) {
      break;
    }
    k++;
  }
  if (k == 2000) {
    cout << "No" << endl;
    return 0;
  }

  vector<vector<ll>> A(k);
  ll t = 1;
  REP(i, 0, k) {
    ll p = 1;
    while (A[i].size() < k - 1) {
      A[i].push_back(t);
      A[i + p].push_back(t);
      t++;
      p++;
    }
  }

  cout << "Yes" << endl;
  cout << k << endl;
  REP(i, 0, k) {
    cout << A[i].size();
    REP(j, 0, A[i].size()) cout << " " << A[i][j];
    cout << endl;
  }
}
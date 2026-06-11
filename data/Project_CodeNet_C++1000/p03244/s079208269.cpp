#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, int> op, ep;
  for (int i = 0; i < n / 2; i++) {
    int v, w;
    cin >> v >> w;
    op[v]++;
    ep[w]++;
  }

  int op1 = 0;
  int mxop1 = 0, mxop2 = 0;
  int ep1 = 0;
  int mxep1 = 0, mxep2 = 0;

  for (auto oq : op) {
    if (oq.second >= mxop1) {
      op1 = oq.first;
      mxop1 = oq.second;
    }
  }

  for (auto oq : op) {
    if (oq.first != op1 && oq.second >= mxop2) {
      mxop2 = oq.second;
    }
  }

  for (auto eq : ep) {
    if (eq.second >= mxep1) {
      ep1 = eq.first;
      mxep1 = eq.second;
    }
  }

  for (auto eq : ep) {
    if (eq.first != ep1 && eq.second >= mxep2) {
      mxep2 = eq.second;
    }
  }

  int ans;
  if (op1 != ep1) {
    ans = n - (mxop1 + mxep1);
  } else {
    ans = n - max(mxop1 + mxep2, mxop2 + mxep1);
  }

  cout << ans << '\n';

  return 0;
}

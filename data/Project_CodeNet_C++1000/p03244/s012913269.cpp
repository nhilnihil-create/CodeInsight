#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int n;

  vector<int> num(100001);
  vector<int> num2(100001);
  map<int, int> mp1;
  map<int, int> mp2;
  cin >> n;

  REP(i, n) {
    int x;
    cin >> x;
    if (i % 2 == 0) {
      if (mp1.count(x))
        mp1.at(x)++;
      else
        mp1[x] = 1;
    } else {
      if (mp2.count(x))
        mp2.at(x)++;
      else
        mp2[x] = 1;
    }
  }
  int X1, M1 = 0, X2, M2 = 0;
  int Y1, M3 = 0, Y2, M4 = 0;

  for (auto p1 : mp1) {
    auto k = p1.first;
    auto v = p1.second;
    if (M1 < v) {
      X1 = k;
      M1 = v;
    }
  }

  mp1.erase(X1);

  for (auto p1 : mp1) {
    auto k = p1.first;
    auto v = p1.second;
    if (M3 < v) {
      Y1 = k;
      M3 = v;
    }
  }

  for (auto p2 : mp2) {
    auto k = p2.first;
    auto v = p2.second;
    if (M2 < v) {
      X2 = k;
      M2 = v;
    }
  }
  mp2.erase(X2);

  for (auto p2 : mp2) {
    auto k = p2.first;
    auto v = p2.second;
    if (M4 < v) {
      Y2 = k;
      M4 = v;
    }
  }

  if (X1 != X2)
    cout << n - (M1 + M2) << endl;
  else
    cout << n - max(M1 + M4, M2 + M3) << endl;
}
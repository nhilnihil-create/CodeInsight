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

set<int> pool;
set<int> sums;

vi primevec(int m, int n) {
  vi ret;
  vector<bool> num(n + 1);
  for (int i = 2; i * i < n; i++) {
    if (!num.at(i)) {
      for (int j = 2; i * j <= n; j++) {
        num.at(i * j) = 1;
      }
    }
  }
  for (int i = m; i <= n; i++) {
    if (!num.at(i) && i % 5 == 1) ret.push_back(i);
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N;
  cin >> N;
  vi prime = primevec(2, 55555);

  for (int i = 0; i < N; i++) cout << prime.at(i) << " ";
  cout << "\n";
}
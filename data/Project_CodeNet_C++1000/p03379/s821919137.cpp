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
  int N, tmp;
  cin >> N;
  vi X(N), Y(N);
  REP(i, N) {
    cin >> tmp;
    X.at(i) = tmp;
    Y.at(i) = tmp;
  }
  sort(X.begin(), X.end());
  int s = X.at((N / 2) - 1), l = X.at(N / 2);
  for (auto a : Y) {
    if (a <= s)
      cout << l << endl;
    else if (a >= l)
      cout << s << endl;
  }
}
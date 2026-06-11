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
  int N, K;
  cin >> N >> K;
  vi A(N);
  REP(i, N) cin >> A.at(i);
  if (N == K) {
    cout << 1 << endl;
    return 0;
  }
  int count = 0;
  for (auto a : A) {
    if (a == 1)
      break;
    else
      count++;
  }
  bool flag = (count < N - count - 1);
  int mod1 = count % (K - 1);
  int mod2 = (N - count - 1) % (K - 1);
  if (mod1 != 0 && mod1 < mod2) {
    cout << (count + (K - 1 - 1)) / (K - 1) +
                (N - count - 1 - (K - mod1) + (K - 1 - 1)) / (K - 1)
         << endl;
  } else if (mod2 != 0 && mod1 >= mod2) {
    cout << (count - (K - mod2) + (K - 1 - 1)) / (K - 1) +
                (N - count - 1 + (K - 1 - 1)) / (K - 1)
         << endl;
  } else {
    cout << (count + (K - 1 - 1)) / (K - 1) +
                (N - count - 1 + (K - 1 - 1)) / (K - 1)
         << endl;
  }
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int costA, costB;
  costA = costB = 0;
  int P;
  rep(i, M) {
    cin >> P;
    if(P < X) {
      costA++;
    }
    else {
      costB++;
    }
  }
  cout << min(costA, costB) << endl;
}
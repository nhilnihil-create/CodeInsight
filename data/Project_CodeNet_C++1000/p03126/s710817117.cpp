#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(M);
  int I, co, X;
  co = 0;
  rep(i, M) {
    vec.at(i) = 0;
  }
  rep(i, N) {
    cin >> I;
    rep(j, I) {
      cin >> X;
      vec.at(X - 1) += 1;
    }
  }
  rep(i, M) {
    if(vec.at(i) == N) {
      co++;
    }
  }
  cout << co << endl;
}
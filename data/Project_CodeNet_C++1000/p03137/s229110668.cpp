#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve(long long N, long long M, std::vector<long long> X) {
  sort(X.begin(), X.end());
  vector<ll> Y;
  for(int i = 0 ; i + 1 < X.size() ; i++) Y.push_back(X[i+1] - X[i]);
  sort(Y.rbegin(), Y.rend());
  ll sum = 0;
  for(int i = 0 ; i < N - 1 && i < Y.size() ; i++){
    sum += Y[i];
  }
  cout << X.back() - X.front() - sum << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> X(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &X[i]);
  }
  solve(N, M, std::move(X));
  return 0;
}


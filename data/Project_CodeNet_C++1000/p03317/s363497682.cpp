#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;

int main() {
  ll N, K, oneplace;//oneplaceは１が下から何桁目かを表す
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  rep(i,N) {
    if(A[i] == 1) {
      oneplace = i + 1;
      break;
    }
  }
  cout << (N + K - 3)/(K - 1)<< endl;
  return 0;
}

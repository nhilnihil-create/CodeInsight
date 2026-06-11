#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  cout << abs(A.back() - A.front()) << endl;
  
  return 0;
}
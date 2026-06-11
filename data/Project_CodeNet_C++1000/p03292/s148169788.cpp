#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  vector<int> A(3);
  rep(i, 3) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  cout << A[1] - A[0] + A[2] - A[1] << endl;
  
  return 0;
}
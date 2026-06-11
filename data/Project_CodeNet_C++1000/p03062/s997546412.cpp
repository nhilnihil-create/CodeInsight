#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

int main() {
  int N, cnt = 0;
  cin >> N;
  vector<Int> A(N);
  rep(i,N) {
    cin >> A[i];
    if (A[i] < 0) cnt++;
  }
  
  if (cnt % 2 == 0) {
    Int ans = 0;
    rep(i,N) {
      if (A[i] > 0) ans += A[i];
      else if (A[i] < 0) ans -= A[i];
    }
    cout << ans << endl;
    return 0;
  }
  else {
    sort(A.begin(),A.end());
    if (cnt == N) {
      Int ans = 0;
      rep(i,N-1) {
        ans -= A[i];
      }
      ans += A[N-1];
      cout << ans << endl;
      return 0;
    }
    else {
      Int lastminus = A[0], firstnonminus, index;
      rep(i,N) {
        if (A[i] < 0) {
          lastminus = A[i];
          continue;
        }
        else {
          firstnonminus = A[i];
          index = i;
          break;
        }
      }
      Int ans = 0;
      if (-lastminus >= firstnonminus) {
        rep(i,N) {
          if (A[i] < 0) ans -= A[i];
          else if (i == index) ans -= A[i];
          else ans += A[i];
        }
      }
      else {
        rep(i,N) {
          if (A[i] < 0 && i != index-1) ans -= A[i];
          else ans += A[i];
        }
      }
      cout << ans << endl;
      return 0;
    }
  }
}
        
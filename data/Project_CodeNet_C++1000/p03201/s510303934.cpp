#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rrep(i, n) for (int i = (n); i >= 0; --i)

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  map<int, int> m;
  rep(i, N) {
    cin >> A[i];
    ++m[A[i]];
  }
  sort(A.begin(), A.end());

  int ans = 0;
  rrep(i, N - 1) {
    if (m[A[i]] == 0) continue;
    --m[A[i]];
    int pow = 1;
    while (2 * pow <= A[i]) pow *= 2;
    if (m[2 * pow - A[i]] > 0) {
      ++ans;
      --m[2 * pow - A[i]];
    }
  }
  cout << ans << endl;

  return 0;
}

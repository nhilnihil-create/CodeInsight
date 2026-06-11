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
  vector<int> X(N);
  vector<int> sorttedX(N);
  rep(i, N) {
    cin >> X[i];
    sorttedX[i] = X[i];
  }

  sort(sorttedX.begin(), sorttedX.end());
  int centerPos = N / 2;
  int centerNum = sorttedX[centerPos];

  rep(i, N) {
    if (X[i] < centerNum) {
      cout << sorttedX[centerPos] << endl;
    } else {
      cout << sorttedX[centerPos - 1] << endl;
    }
  }
  
  return 0;
}
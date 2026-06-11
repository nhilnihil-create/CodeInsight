#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N, K;
  cin >> N >> K;

  if (N % K == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
  
  return 0;
}
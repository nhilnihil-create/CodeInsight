#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K, s = 1;
  cin >> N >> K;
  rep(i, N) {
    s = min(s * 2, s + K);
  }
  cout << s << endl;
}
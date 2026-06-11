#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main () {
  int N;
  cin >> N;

  int M = 0;
  vector<int> h(N, 0);
  rep(i, N) {
    cin >> h[i];
    M = max(h[i], M);
  }
  
  int ans = 0;
  for (int i = 1; i <= M ; i++) {
    bool flag = false;
    for (int j = 0; j < N; j++) {
      if (h[j] >= i) {
        flag = true;
      }
      if ((h[j] < i || j == N - 1) && flag == true) {
        ans++;
        flag = false;
      }
    }
  }
  cout << ans;
}
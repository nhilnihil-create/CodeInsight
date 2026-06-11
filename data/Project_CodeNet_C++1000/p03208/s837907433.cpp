#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}

int main() {
  int N, K;
  cin >> N >> K;
  
  int h[N];
  for (int i = 0;i < N; i++) cin >> h[i];
  
  sort(h, h+N);
  
  int ans = h[K-1] - h[0];
  for (int i = 1; i < N-K+1; i++) {
    chmin(ans, h[i+K-1]-h[i]);
  }
  
  cout << ans << endl;
}
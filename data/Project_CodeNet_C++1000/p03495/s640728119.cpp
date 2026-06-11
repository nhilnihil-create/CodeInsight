#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, tmp;
  cin >> N >> K;
  vector<int> ball(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    ball.at(tmp)++;
  }
  
  sort(ball.begin(), ball.end());
  int ans = 0;
  for (int i = 1; i < N + 1 - K; i++) {
    ans += ball.at(i);
  }
  
  cout << ans << endl;
}

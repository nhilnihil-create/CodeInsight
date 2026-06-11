#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> jewel(N);
  for(int i = 0; i < N; i++) {
    cin >> jewel.at(i);
  }
  int ans = 0;
  for(int x = 0; x <= min(N, K); x++) {
    for(int y = 0; y <= min(N, K) - x; y++) {
      int count = 0;
      priority_queue<int, vector<int>, greater<int>> select;
      for(int i = 0; i < x; i++) {
        count += jewel.at(i);
        select.push(jewel.at(i));
      }
      for(int i = 0; i < y; i++) {
        count += jewel.at(N - 1 - i);
        select.push(jewel.at(N - 1 - i));
      }
      for(int i = 0; i < min(K - x - y, x + y); i++) {
        int a = select.top();
        if(a < 0) {
          count -= a;
          select.pop();
        }
        else {
          break;
        }
      }
      if(count > ans) {
        ans = count;
      }
    }
  }
  cout << ans << endl;
}
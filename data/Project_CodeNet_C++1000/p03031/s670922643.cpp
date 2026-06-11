#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> connect(M, vector<bool> (N, false));
  for(int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int s;
      cin >> s;
      connect.at(i).at(s - 1) = true;
    }
  }
  vector<int> mod(M);
  for(int i = 0; i < M; i++) {
    cin >> mod.at(i);
  }
  int ans = 0;
  for(int i = 0; i < (1 << N); i++) {
    bitset<10> Switch(i);
    for(int j = 0; j < M; j++) {
      int count = 0;
      for(int k = 0; k < N; k++) {
        if(connect.at(j).at(k) && Switch.test(k)) {
          count++;
        }
      }
      if(count % 2 != mod.at(j)) {
        break;
      }
      else if(j == M - 1) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
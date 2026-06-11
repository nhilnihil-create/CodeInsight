#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int64_t> data(N);
  for(int i = 0; i < N; i++) {
    cin >> data.at(i);
  }
  sort(data.begin(), data.end());
  vector<pair<int64_t, int>> change(M);
  for(int i = 0; i < M; i++) {
    int64_t c;
    int b;
    cin >> b >> c;
    change.at(i) = make_pair(-c, b);
  }
  sort(change.begin(), change.end());
  int keep = 0;
  bool judge = false;
  for(int i = 0; i < M; i++) {
    int64_t c = (-1) * change.at(i).first;
    int b = change.at(i).second;
    for(int j = keep; j < min(keep + b, N); j++) {
      if(data.at(j) < c) {
        data.at(j) = c;
      }
      else {
        judge = true;
        break;
      }
    }
    if(judge) {
      break;
    }
    keep += b;
    if(keep >= N) {
      break;
    }
  }
  int64_t ans = 0;
  for(int i = 0; i < N; i++) {
    ans += data.at(i);
  }
  cout << ans << endl;   
}

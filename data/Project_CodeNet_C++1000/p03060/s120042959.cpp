#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> V(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> V.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  int ans = 0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<20> s(tmp);
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        x += V.at(i);
        y += C.at(i);
      }
    }
    ans = max(ans, x - y);
  }
  cout << ans << endl;
}

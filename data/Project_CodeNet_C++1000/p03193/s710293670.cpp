#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N, H, W, A, B;
  cin >> N >> H >> W;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;
    if (A >= H && B >= W) cnt++;
  }

  cout << cnt << endl;
}
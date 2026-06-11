#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> V(N);
  for (int i = 0; i < N; i++) cin >> V.at(i);
  int ans = 0, cnt;
  for (int i = 0; i < N; i++){
    cnt = 0;
    for (int j = 0; j * V.at(i) + 1 <= D; j++){
      cnt++;
    }
    ans += cnt;
  }
  cout << ans + X << endl;
}
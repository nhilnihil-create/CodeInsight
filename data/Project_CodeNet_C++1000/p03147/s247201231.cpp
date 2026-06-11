#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<int>fl(N + 2);
  for (int i = 1; i <= N; i ++) cin >> fl[i];
  fl[0] = fl[N+1] = 0;
  int ans = 0;
  for (int i = 0; i < 100; i ++) {
    int kj = 0;
    for (int j = 1; j < N + 2; j ++) {
      if (fl[j - 1] <= 0 && fl[j] > 0) {
        kj ++;
      }
    }
    ans += kj;
    for (int j = 1; j <= N; j ++) fl[j] --;
  }
  cout << ans << endl;
}

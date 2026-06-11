#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> b(N),ans(N,0);
  for (int i=0; i<N; i++) {
    cin >> b[i];
    if (b[i] > i+1) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  
  int num,loc;
  for (int i=N-1; i>=0; i--) {
    num = i - (b[i] - 1) + 1;
    loc = N;
    while (loc >= 0) {
      if (num == 0) {
        ans[loc] = b[i];
        break;
      }
      if(ans[loc-1] == 0) {
        num--;
      }
      loc--;
    }
  }
  for (int i=0; i<N; i++) {
    cout << ans[i] << endl;
  }
  
}

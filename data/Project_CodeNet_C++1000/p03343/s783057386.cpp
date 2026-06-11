#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  A.push_back(-INF);
  int tv = INF;
  int fv = -1;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    bool ok = false;
    for (int i = 0; i < N; i++){
      int cnt = 0;
      int cnt2 = 0;
      int cnt3 = 0;
      for (int j = 0; j <= N; j++){
        if (A[j] >= A[i] - mid){
          cnt2++;
          if (A[j] <= A[i]){
            cnt3++;
          }
        } else {
          cnt += max(min(cnt2 - K + 1, cnt3), 0);
          cnt2 = 0;
          cnt3 = 0;
        }
      }
      if (cnt >= Q){
        ok = true;
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  cin >> N >> A >> B;
  if ((long long) A * B < N){
    cout << -1 << endl;
  } else if (A + B - 1 > N){
    cout << -1 << endl;
  } else {
    vector<int> cnt(B, 1);
    cnt[0] = A;
    int M = N - A - B + 1;
    for (int i = 1; i < B; i++){
      if (M % (B - 1) >= i){
        cnt[i] += M / (B - 1) + 1;
      } else {
        cnt[i] += M / (B - 1);
      }
    }
    vector<int> ans;
    for (int i = 0; i < B; i++){
      for (int j = N - cnt[i] + 1; j <= N; j++){
        ans.push_back(j);
      }
      N -= cnt[i];
    }
    N = ans.size();
    for (int i = 0; i < N; i++){
      cout << ans[i];
      if (i < N - 1){
        cout << ' ' ;
      }
    }
    cout << endl;
  }
}
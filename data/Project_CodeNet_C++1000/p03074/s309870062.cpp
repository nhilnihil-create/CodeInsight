#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  // 0のかたまりの数
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(i == 0){
      if(S.at(i) == '0') {
        count++;
      }
    }
    else if(S.at(i) == '0' && S.at(i - 1) == '1') {
      count++;
    }
  }
  if(count <= K) {
    cout << N << endl;
  }
  else {
    // 0のかたまりの右端と左端の位置
    vector<int> L, R;
    for(int i = 0; i < N; i++) {
      if(i == 0) {
        if(S.at(0) == '0') {
          L.push_back(i);
        }
      }
      else if(S.at(i) == '0' && S.at(i - 1) == '1') {
        L.push_back(i);
      }
      if(i == N - 1) {
        if(S.at(i) == '0') {
          R.push_back(i);
        }
      }
      else if(S.at(i) == '0' && S.at(i + 1) == '1') {
        R.push_back(i);
      }
    }
    reverse(L.begin(), L.end());
    //残す0の塊の数
    int a = count - K;
    int ans = 0;
    for(int i = 0; i <= a; i++) {
      //左にi個残す
      int total;
      if(i == 0) {
        total = L.at(a - i - 1);
      }
      else if(i == a) {
        total = N - R.at(i - 1) - 1;
      }
      else {
        total = L.at(a - i - 1) - R.at(i - 1) - 1;
      }
      if(total > ans) {
        ans = total;
      }
    }
    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N, K;
  cin >> N >> K;
  
  // 計算をしていく
  int sumKeisan = 1;
  rep(i, N) {
    if (sumKeisan * 2 < sumKeisan + K) {
      sumKeisan *= 2;
    }
    else sumKeisan += K;
  }
 
  // 計算結果を出力
  cout << sumKeisan << endl;
}
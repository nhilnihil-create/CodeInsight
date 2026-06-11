#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;

// 各桁の和を計算する関数
int SumDigi(int x) {
  int sum = 0;
  while (x > 0) { // n が 0 になるまで
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  int ans = 1000000;
  rep(i, n-1){
    int sumAB = SumDigi(i+1) + SumDigi(n-i-1);
    ans = min(ans,sumAB);
  }
  cout << ans << endl;
}

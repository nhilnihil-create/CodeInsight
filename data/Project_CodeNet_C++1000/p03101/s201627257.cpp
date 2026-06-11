#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  int bH,bW;
  int sum;
  
  cin >> h >> w >> bH >> bW;
  
  sum = h * w;
  
  // 総和 - (塗る列 + 塗る行 - 重複)
  cout << sum - (h * bW + w * bH - bH * bW);
}

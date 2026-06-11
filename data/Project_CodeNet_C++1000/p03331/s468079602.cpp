#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 各桁の和を計算する関数
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}



int main(){
int n;
cin >> n;

int ans = 100;

for (int i = 1; i < n; i++)
{
  int x = findSumOfDigits(i);
  int y = findSumOfDigits(n-i);

  if(x + y < ans){
    ans = x + y;
  }
}

cout << ans << endl;
}
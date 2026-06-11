#include <bits/stdc++.h>
using namespace std;
int F(int num) {
  int sum = 0;
  int remain;
  while (num > 0) {
    remain = num % 10;
    sum += remain;
    num = num / 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;
  int ans = N;
  for (int x = 1; x <= N/2; x++) {
    int y = N - x;
    int result = F(x) + F(y);
    if (result < ans) {
      ans = result;
    } 
  }
  cout << ans << "\n";
}

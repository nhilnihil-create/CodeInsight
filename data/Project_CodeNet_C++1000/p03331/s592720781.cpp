#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

// 各桁の合計を求める
int findSumOfDigits(int n) {
  int sum = 0;
  while(n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  int ans = n;

  for (int i = 1; i < n; i++) {
    int a = i;
    int b = n - a;

    int sum_a = findSumOfDigits(a);
    int sum_b = findSumOfDigits(b);
    int sum = sum_a + sum_b;

    ans = min(ans, sum);
  }
  cout << ans << endl;


  return 0;
}
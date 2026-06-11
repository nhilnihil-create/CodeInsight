#include <bits/stdc++.h>
using namespace std;

int diveder(long long x, int d){
  int ret = 0;
  while(x > 0){
    ret += x % d;
    x /= d;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  long long N;
  cin >> N;
  int min = 999999;
  for (int i = 0; i < N / 6 + 1; i++) {
    long long n = N;
    n -= i * 6;
    int j = n / 9;
    int ans = n % 9;
    ans += diveder(i, 6) + diveder(j, 9);
    if(ans < min){
      min = ans;
    }
  }
  cout << min <<endl;
}

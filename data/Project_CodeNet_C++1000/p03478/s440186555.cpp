#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int sum = 0;
    int x = i;
    while(x) {
      sum += x % 10;
      x /= 10;
    }
    if(a <= sum && sum <= b) {
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}
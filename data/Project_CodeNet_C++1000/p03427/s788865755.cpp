#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 各桁の数の和
int DigitSum(ll x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;
  
  string s = to_string(n);
  
  cout << max<int>(DigitSum(n), (s.size() - 1) * 9 + s[0] - '1') << '\n';
}
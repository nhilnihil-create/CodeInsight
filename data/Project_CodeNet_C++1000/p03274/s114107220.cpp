#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  for(int i = 0; i < N; i++) {
    cin >> x[i];
  }
  int ans = MAX_INT;
  for(int i = 0; i + K < N + 1; i++) {
    int l = x[i], r = x[i + K - 1];
    ans = min(ans, min(abs(r) + abs(r - l), abs(l) + abs(r - l)));
  }

  cout << ans << endl;

  return 0;
}

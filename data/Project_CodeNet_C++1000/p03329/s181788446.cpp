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

// x^y%p
long long modpow(long long x, long long y, long long p=1) {
    long long res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = res * x % p;
        y = y>>1;
        x = x * x % p;
    }
    return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int res = N;
  for(int i = 0; i <= N; i++) {
    int cc = 0;
    int t = i;
    while (t > 0) {
      cc += t % 6;
      t /= 6;
    }
    t = N - i;
    while (t > 0) {
      cc += t % 9;
      t /= 9;
    }
    if(res > cc) {
      res = cc;
    }
  }

  cout << res << endl;

  return 0;
}

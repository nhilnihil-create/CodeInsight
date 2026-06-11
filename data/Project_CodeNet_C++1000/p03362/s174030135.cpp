#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for(int i=0;i<(int)(n);++i)
template <typename T> ll gcd(T a, T b) {return b?gcd(b, a%b):a;}
template <typename T> ll lcm(T a, T b) {return a * b / gcd(a, b);};
template <typename T> inline void chmin(T &a, const T& b){if(a>b)a=b;}
template <typename T> inline void chmax(T &a, const T& b){if(a<b)a=b;}

inline bool isPrime(int x) {
  bool ans = true;
  if (x <= 1) ans = false;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      ans = false;
      break;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 11; i <= 55555; i += 5) {
    if (isPrime(i)) {
      cout << i;
      if (--n == 0) {
        break;
      }
      cout << " ";
    }
  }
  cout << '\n';
}

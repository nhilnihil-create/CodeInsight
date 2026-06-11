#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
const int INF = 2e9;
const int MOD = 1e9 + 7;

int main() {
   int n;
   cin >> n;
   if (n % 10 == 0) {
      cout << 10 << endl;
      return 0;
   }
   int ans = 0;
   while (n) {
      ans += n % 10;
      n /= 10;
   }
   cout << ans << endl;
   return 0;
}
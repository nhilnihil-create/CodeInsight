#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
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

const int INF = 1 << 20;
const int MOD = 1e9 + 7;

map<int, int> prime(int n) {
   map<int, int> v;
   for (int i = 2; (ll)i * i <= n; i++) {
      while (n % i == 0) {
         v[i]++;
         n /= i;
      }
   }
   if (n > 1) v[n]++;
   return v;
}
int main() {
   int n;
   cin >> n;
   map<int, int> pr;
   rep(i, 1, n + 1) {
      auto mp = prime(i);
      for (auto s : mp) {
         pr[s.first] += s.second;
      }
   }
   int ans = 0;
   rep(i, 2, n + 1) {
      if (pr[i] >= 74) ans++;
   }
   rep(i, 2, n + 1) {
      rep(j, 2, n + 1) {
         if (i != j && pr[i] >= 4 && pr[j] >= 14) ans++;
      }
   }
   rep(i, 2, n + 1) {
      rep(j, 2, n + 1) {
         if (i != j && pr[i] >= 2 && pr[j] >= 24) ans++;
      }
   }
   rep(i, 2, n + 1) {
      rep(j, 2, n + 1) {
         rep(k, j + 1, n + 1) {
            if (i != j && i != k && pr[i] >= 2 && pr[j] >= 4 &&
                pr[k] >= 4)
               ans++;
         }
      }
   }
   cout << ans << endl;
   return 0;
}
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
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   rep(i, 0, m) {
      int k;
      cin >> k;
      rep(j, 0, k) {
         int s;
         cin >> s;
         s--;
         a[s] |= 1 << i;
      }
   }
   int p = 0;
   rep(i, 0, m) {
      int pi;
      cin >> pi;
      p |= pi << i;
   }
   int ans = 0;
   rep(S, 0, 1 << n) {
      int t = 0;
      rep(i, 0, n) {
         if ((S >> i) & 1) {
            t ^= a[i];
         }
      }
      if (t == p) ans++;
   }
   cout << ans << endl;
   return 0;
}
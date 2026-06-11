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

   priority_queue<pair<int, int>> q;
   int n, m;
   cin >> n >> m;
   rep(i, 0, n) {
      int a;
      cin >> a;
      q.push(make_pair(a, 1));
   }
   rep(i, 0, m) {
      int b, c;
      cin >> b >> c;
      q.push(make_pair(c, b));
   }
   ll ans = 0;
   rep(i, 0, n) {
      P p = q.top();
      q.pop();
      ans += p.first;
      p.second--;
      if (p.second > 0) q.push(p);
   }
   cout << ans << endl;
   return 0;
}
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

int N, M, Q;
vector<vector<int>> sum;
void bulidTable(vector<int> L, vector<int> R) {
   sum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
   rep(i, 0, M) { sum[L[i]][R[i]]++; }
   rep(i, 1, N + 1) {
      rep(j, 1, N + 1) {
         sum[i][j] += sum[i - 1][j];
         sum[i][j] += sum[i][j - 1];
         sum[i][j] -= sum[i - 1][j - 1];
      }
   }
}
int getSumRange(int L, int R) {
   int res = sum[R][R] - sum[R][L - 1] - sum[L - 1][R] + sum[L - 1][L - 1];
   return res;
}
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   cin >> N >> M >> Q;
   vector<int> L(M), R(M);
   rep(i, 0, M) { cin >> L[i] >> R[i]; }
   vector<int> p(Q), q(Q);
   rep(i, 0, Q) cin >> p[i] >> q[i];
   bulidTable(L, R);
   rep(i, 0, Q) {
      int ans = getSumRange(p[i], q[i]);
      cout << ans << endl;
   }
   return 0;
}
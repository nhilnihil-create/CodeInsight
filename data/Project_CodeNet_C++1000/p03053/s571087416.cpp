#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
const int INF = 10000;
int A[1000][1000];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int h, w; cin >> h >> w;
   rep(i,h){
      rep(j,w){
         char c; cin >> c;
         A[i][j] = c=='#' ? 0 : INF;
      }
   }
   rep(i,h){
      rep(j,w-1){
         A[i][j+1] = min(A[i][j]+1, A[i][j+1]);
         A[i][w-j-2] = min(A[i][w-j-1]+1, A[i][w-j-2]);
      }
   }
   rep(j,w){
      rep(i,h-1){
         A[i+1][j] = min(A[i][j]+1, A[i+1][j]);
         A[h-i-2][j] = min(A[h-i-1][j]+1, A[h-i-2][j]);
      }
   }
   int ans = 0;
   rep(i,h)rep(j,w)ans = max(ans, A[i][j]);
   cout << ans << endl;
}
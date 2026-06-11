#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
using namespace std;
template < class T > using vec = std::vector< T >;
template < class T > void print(T &x) { cout << x << "\n"; }
typedef long long ll;
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI = acos(-1.0);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[100100][3];
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  // 0 -- A, 1 -- AB, 2 -- ABC
  int countVal=1;
  REPS(i,N){
    char si = S[i-1];
    REP(j,3){
      if ((si==('A'+j)) || (si=='?')){
        //増加分
        dp[i][j]+= (j==0? countVal : dp[i-1][j-1]);
        dp[i][j]%=MOD;
        REP(k,3){
          dp[i][k]+=dp[i-1][k];
          dp[i][k]%=MOD;
        }
      }
    }
    if (si=='?'){
      countVal*=3;
      countVal%=MOD;
    }
  }
  print(dp[N][2]);
  return 0;
}

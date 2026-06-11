#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define Pl pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;



int main()
{
  int N; cin >> N;
  vector<vector<int>> arr(N, vector<int>(N));
  rep(i, 0, N) rep(k, 0, N) cin >> arr[i][k];
  vector<vector<int>> dp((1 << N), vector<int>(N + 1, 0));
  dp[0][0] = 1;

  rep(i, 0, N){
    for(int bit = 0; bit < (1 << N); ++bit){
      if(dp[bit][i] == 0) continue;
      rep(k, 0, N){
        if(arr[i][k] && (bit & (1 << k)) == 0){
          dp[bit | (1 << k)][i + 1] += dp[bit][i];
          dp[bit | (1 << k)][i + 1] %= MOD;
        }
      }
    }
  }

  cout << dp[(1 << N) - 1][N] << endl;
}

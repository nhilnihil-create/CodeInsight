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
  vector<double> arr(N);
  rep(i, 0, N) cin >> arr[i];
  vector<vector<double>> dp(N + 1, vector<double>(N + 1));
  dp[0][0] = 1.0;

  rep(i, 0, N){
    repe(k, 0, i){
      dp[i + 1][k + 1] += dp[i][k] * arr[i];
      dp[i + 1][k] += dp[i][k] * (1.0 - arr[i]);
    }
  }

  double ans = 0.0;
  repe(i, N / 2 + 1, N){
    ans += dp[N][i];
  }
  
  printf("%.10f\n", ans);

}

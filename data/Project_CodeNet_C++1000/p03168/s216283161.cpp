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

int N;
vector<double> arr;
vector<vector<double>> dp;

double
rec(int n, int front)
{
  if(dp[n][front] != 0) return dp[n][front];
  if(n == 0) return 1.0;
  
  rec(n - 1, front - 1);

  for(int i = n; i > 0; --i){
    dp[n][i] += dp[n - 1][i - 1] * arr[n - 1];
    dp[n][i - 1] += dp[n - 1][i - 1] * (1.0 - arr[n - 1]);
  }

  return dp[n][front];
}


int main()
{
  cin >> N;
  arr.resize(N);
  rep(i, 0, N) cin >> arr[i];
  dp.assign(N + 1, vector<double>(N + 1, 0));
  dp[0][0] = 1.0;

  rec(N, N);

  double ans = 0.0;
  repe(i, N / 2 + 1, N){
    ans += dp[N][i];
  }
  
  printf("%.10f\n", ans);
}

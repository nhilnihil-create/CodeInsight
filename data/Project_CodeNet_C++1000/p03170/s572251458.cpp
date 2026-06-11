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
  int N, K; cin >> N >> K;
  vector<int> arr(N);
  rep(i, 0, N) cin >> arr[i];
  vector<bool> dp(K + 1, false);

  repe(i, 1, K){
    rep(k, 0, N){
      if(i - arr[k] >= 0){
        if(!dp[i - arr[k]]) dp[i] = true;
      }
    }
  }

  if(dp[K]) cout << "First" << endl;
  else cout << "Second" << endl;
}

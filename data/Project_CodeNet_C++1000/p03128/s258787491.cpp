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
//#define P pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int main()
{
  int N, M; cin >> N >> M;
  vector<int> aba(M);
  rep(i, 0, M) cin >> aba[i];
  vector<int> value(10);
  value[1] = 2;
  value[2] = 5;
  value[3] = 5;
  value[4] = 4;
  value[5] = 5;
  value[6] = 6;
  value[7] = 3;
  value[8] = 7;
  value[9] = 6;
  vector<string> dp(N + 1, "0");
  dp[0] = "";

  repe(num, 0, N){
    if(dp[num] == "0") continue;
    rep(i, 0, M){
      int next = num + value[aba[i]];
      if(num + value[aba[i]] <= N){
        string tmp = dp[num];
        tmp.push_back('0' + aba[i]);
        if(dp[next].size() < tmp.size()){
          dp[next] = tmp;
        } else if(dp[next].size() == tmp.size()){
          if(dp[next] < tmp) dp[next] = tmp;
        }
      }
    }
  }
  string ans = dp[N];
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

}

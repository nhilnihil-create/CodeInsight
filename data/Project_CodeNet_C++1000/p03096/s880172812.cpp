#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define sqr(x)  ((x) * (x)) 
#define cub(x)  ((x) * (x) * (x))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// int gcd(int a,int b){return b?gcd(b,a%b):a;}

ll dp[200100];
ll colorsum[200100];
ll c[200100];
ll MOD = pow(10,9) + 7;

int main() {
  ll n; cin >> n;
  FOR(i,0,n-1) cin >> c[i];

  dp[0] = 1;
  FOR(i,1,n){
    dp[i] += dp[i-1];

    if(c[i-1]!=c[i]){
      dp[i] += colorsum[c[i-1]];
      dp[i] %= MOD;
      colorsum[c[i-1]] = dp[i]; 
    }
  }

  cout << dp[n] << endl;



}

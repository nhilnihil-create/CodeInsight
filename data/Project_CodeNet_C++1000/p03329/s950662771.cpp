#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<int> dp(1000000,INF);
  dp[0]=0;
  for(int i=1; i<1000000; i++){
    chmin(dp[i],dp[i-1]+1);
    for(int j=6; j<=i; j*=6){
      chmin(dp[i],dp[i-j]+1);
    }
    for(int j=9; j<=i; j*=9){
      chmin(dp[i],dp[i-j]+1);
    }
  }
  cout << dp[n] << endl;
}


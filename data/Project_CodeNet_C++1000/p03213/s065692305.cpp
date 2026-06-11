#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

int dp[27][100];
int main(){
  int N;
  cin >> N;
  map<int, int> mp;
  if(N == 1){
    cout << 0 << endl;
    return 0;
  }
  FOR(k, 2, N+1){
    int n = k;
    for(int i = 2; i * i <= k; i++){
      while(n % i == 0){
        mp[i]++;
        n /= i;
      }
    }
    if(n != 1){
      mp[n]++;
    }
  }
  dp[0][1] = 1;
  int idx = 0;
  for(auto p : mp){
    FOR(i, 1, p.second+2){
      FOR(j, 1, 76){
        if(dp[idx][j] == 0 || j * i > 75) continue;
        dp[idx+1][j*i] += dp[idx][j];
      }
    }
    idx++;
  }
  cout << dp[idx][75] << endl;

  return 0;
}

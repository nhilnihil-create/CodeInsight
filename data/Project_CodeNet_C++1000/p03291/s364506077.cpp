#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

string S;

int main(){
  cin >> S;
  vector<vector<ll>> sum(4, vector<ll>(S.size()+1, 0));
  int n = S.size();
  REP(i, n){
    if(S[i] == '?'){
      S[i] = 'D';
    }
  }
  REP(i, n){
    REP(j, 4){
      sum[j][i+1] = sum[j][i];
    }
    sum[S[i]-'A'][i+1]++;
  }
  const ll mod = 1e9+7;
  ll ans = 0;
  ll cmb = 1, cmb1, cmb2, cmb3;
   cmb = cmb1 = cmb2 = cmb3 = 1;
  REP(i, sum[3][n]){
    if(i < sum[3][n]-1){
      cmb1 *=3;
      cmb1 %= mod;
    }
    if(i < sum[3][n]-2){
      cmb2 *=3;
      cmb2 %= mod;
    }
    if(i < sum[3][n]-3){
      cmb3*=3;
      cmb3 %=mod;
    }
    cmb*=3;
    cmb %=mod;
  }
  FOR(i, 1, n-1){
    if(S[i] == 'B'){
      ans += cmb* sum[0][i] * (sum[2][n]-sum[2][i+1]);
      ans %=mod;
      ans += cmb1 * sum[3][i] * (sum[2][n]-sum[2][i+1]);
      ans %=mod;
      ans += cmb1 * sum[0][i] * (sum[3][n] - sum[3][i+1]);
      ans %=mod;
      ans += cmb2 * sum[3][i]*(sum[3][n] - sum[3][i+1]);
    }
    else if(S[i] == 'D'){
      ans += cmb1 *sum[0][i] * (sum[2][n]-sum[2][i+1]);
      ans %=mod;
      ans += cmb2 * sum[3][i] * (sum[2][n]-sum[2][i+1]);
      ans %=mod;
      ans += cmb2 * sum[0][i] * (sum[3][n] - sum[3][i+1]);
      ans %=mod;
      ans += cmb3 * sum[3][i]*(sum[3][n] - sum[3][i+1]);
    }
    ans %=mod;
  }
  cout << ans << endl;

  return 0;
}

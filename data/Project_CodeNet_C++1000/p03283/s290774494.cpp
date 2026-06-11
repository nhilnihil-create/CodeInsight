#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int dp[500][500] = {0};
int main(){
  int N,M,Q;
  cin>>N>>M>>Q;
  for(int i(0);i<M;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    dp[l][r]++;
  }
  // cout << endl;
  // for(int i(0);i<N;i++){
  //   for(int j(0);j<N;j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < N - i; j++) {
      int w = i + j;
      int h = j;
      dp[h][w] += dp[h+1][w] + dp[h][w-1] - dp[h+1][w-1];
    }
  }
  // for(int i(0);i<N;i++){
  //   for(int j(0);j<N;j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  for(int i(0);i<Q;i++){
    int p,q;
    cin>>p>>q;
    p--;q--;
    cout << dp[p][q] << endl;
  }
  return 0;
}


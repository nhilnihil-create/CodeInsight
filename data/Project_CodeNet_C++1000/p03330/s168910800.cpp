#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N,C;
  cin>>N>>C;
  vector<vector<int>> D(C+1,vector<int>(C+1));
  for(int i(1);i<=C;i++){
    for(int j(1);j<=C;j++){
      cin>>D[i][j];
    }
  }
  int cnt[3][31] = {0};
  for(int i(1);i<=N;i++){
    for(int j(1);j<=N;j++){
      int c;
      cin>>c;
      cnt[(i+j)%3][c]++;
    }
  }
  int ans(INFint);
  for(int i(1);i<=C;i++){
    for(int j(1);j<=C;j++){
      for(int k(1);k<=C;k++){
        if(i == j || j == k || k == i) continue;
        int tmp(0);
        for(int l(1);l<=C;l++){
          tmp += D[l][i]*cnt[0][l];
          tmp += D[l][j]*cnt[1][l];
          tmp += D[l][k]*cnt[2][l];
        }
        ans = min(ans,tmp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

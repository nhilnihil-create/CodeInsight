#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4e2+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n;
ll dp[N][N] , val[N][N];

int main(){

  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> val[i][i];
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ;j++)
      if(i != j) dp[i][j] = inf;

  for(int i = 1 ; i <= n ; i++){
    for(int j = i-1 ; j > 0 ; j--){
      for(int z = j ; z < i ; z++){
        if(dp[j][i] > dp[j][z] + dp[z+1][i] + val[j][z] + val[z+1][i]){
          val[j][i] = val[j][z] + val[z+1][i];
          dp[j][i] = dp[j][z] + dp[z+1][i] + val[j][z] + val[z+1][i];
        }
      }
    }
  }

  cout << dp[1][n] << "\n";

}

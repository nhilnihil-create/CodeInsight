#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, c;
  cin >> n >> c;
  int d[c + 1][c + 1], color[n + 1][n + 1];
  for(int i = 1; i <= c; i++){
    for(int j = 1; j <= c; j++) cin >> d[i][j];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) cin >> color[i][j];
  }
  int cnt[3][35], cst[3][35];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 35; j++){
      cnt[i][j] = 0;
      cst[i][j] = 0;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if((i + j) % 3 == 0){
        cnt[0][color[i][j]]++;
      }else if((i + j) % 3 == 1){
        cnt[1][color[i][j]]++;
      }else{
        cnt[2][color[i][j]]++;
      }
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= c; j++){
      for(int k = 1; k <= c; k++){
        cst[i][j] += cnt[i][k] * d[k][j];
      }
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i <= c; i++){
    for(int j = 1; j <= c; j++){
      for(int k = 1; k <= c; k++){
        if(i != j && j != k && k != i){
          ans = min(ans, cst[0][i] + cst[1][j] + cst[2][k]);
        }
      }
    }
  }

  cout << ans << '\n';
}

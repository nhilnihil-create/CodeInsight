#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n,c;
  cin >> n >> c;
  int d[c][c];
  rep(i,c)rep(j,c)cin >> d[i][j];
  int mod0[30],mod1[30],mod2[30];
  rep(i,30){
    mod0[i] = 0;
    mod1[i] = 0;
    mod2[i] = 0;
  }
  int grid[n][n];
  rep(i,n){
    rep(j,n){
      cin >> grid[i][j];
      grid[i][j]--;
      if((i+j)%3 == 0)mod0[grid[i][j]]++;
      else if((i+j)%3 == 1)mod1[grid[i][j]]++;
      else mod2[grid[i][j]]++;
    }
  }
  int ans = INF;
  rep(i,c){
    rep(j,c){
      rep(k,c){
        if(i==j || j==k || k==i)continue;
        int tmp = 0;
        rep(l,30){
          tmp += mod0[l]*d[l][i] + mod1[l]*d[l][j] + mod2[l]*d[l][k];
        }
        if(ans > tmp)ans = tmp;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
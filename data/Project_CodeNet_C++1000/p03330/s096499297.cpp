#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const int INF=250000005;

int main(){
  int n,C;
  cin>>n>>C;
  vector<vector<int>> d(C,vector<int>(C));
  rep(i,C)rep(j,C) cin>>d[i][j];
  vector<vector<int>> c(3,vector<int>(C));
  rep(i,n)rep(j,n){
    int x;
    cin>>x;
    x--;
    c[(i+j)%3][x]++;
  }
  int ans=INF;
  rep(i,C){
    rep(j,C){
      if(j==i) continue;
      rep(k,C){
        if(k==i||k==j) continue;
        int res=0;
        rep(p,C){
          res+=c[0][p]*d[p][i];
          res+=c[1][p]*d[p][j];
          res+=c[2][p]*d[p][k];
        }
        ans=min(ans,res);
      }
    }
  }
  cout<<ans<<endl;
}
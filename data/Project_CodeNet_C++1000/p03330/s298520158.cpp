#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=1e18;
const ll MOD=1e9+7;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int n,c;
  cin >> n >> c;
  int d[c][c];
  int f[n][n];
  rep(i,c){
    rep(j,c){
      cin >> d[i][j];
    }
  }
  rep(i,n){
    rep(j,n){
      cin >> f[i][j];
      f[i][j]--;
    }
  }
  ll cost[3][c];
  rep(i,3){
    rep(j,c){
      cost[i][j]=0;
    }
  }
  rep(k,c){
    rep(i,n){
      rep(j,n){
        cost[(i+j)%3][k]+=d[f[i][j]][k];
      }
    }
  }
  ll res=INF;
  rep(i,c){
    rep(j,c){
      if(i==j)continue;
      rep(k,c){
        if(k==i || k==j)continue;
        chmin(res,cost[0][i]+cost[1][j]+cost[2][k]);
      }
    }
  }
  cout << res << endl;
}

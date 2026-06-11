#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};


int main(){

  int n,C;
  cin >> n >> C;
  vector<vector<int>> D(C,vector<int>(C));
  REP(i,C)REP(j,C)cin >> D[i][j];
  vector<vector<int>> c(n,vector<int>(n));
  REP(i,n)REP(j,n)cin >> c[i][j];
  vector<vector<int>> v(3,vector<int>(C,0));
  REP(i,n){
    REP(j,n){
      v[(i+j)%3][c[i][j]-1]++;
    }
  }
  ll res = INF;
  REP(i,C){
    ll d1 = 0;
    REP(l,C)d1 += D[l][i]*v[0][l];
    REP(j,C){
      if(i == j)continue;
      ll d2 = 0;
      REP(l,C)d2 += D[l][j]*v[1][l];
      REP(k,C){
        if(i == k || j == k)continue;
        ll d3 = 0;
        REP(l,C)d3 += D[l][k]*v[2][l];
        res = min(res,d1+d2+d3);
      }
    }
  }
  cout << res << endl;

  

  return 0;
}

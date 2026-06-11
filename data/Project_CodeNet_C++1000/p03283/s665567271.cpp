#include<bits/stdc++.h>

using namespace std;
using ll = long long;
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

  int n,m,Q;
  cin >> n >> m >> Q;
  vector<vector<int>> s(n+1,vector<int>(n+1,0));
  vector<vector<int>> a(n+1,vector<int>(n+1,0));
  REP(i,m){
    int l,r;cin >> l >> r;
    a[l][r]++;
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i+1][j+1];
    }
  }
  REP(i,Q){
    int l,r;cin >> l >> r;
    cout << s[r][r] - s[r][l-1] - s[l-1][r] + s[l-1][l-1] << endl;
  }






  



  return 0;
}
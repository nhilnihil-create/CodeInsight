#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

vector<int> dp(mx,inf);

int main(){
  int n,co;
  cin >> n >> co;
  vector<vector<int>> d(50, vector<int>(50));
  vector<vector<int>> c(3, vector<int>(50,0));
  rep(i,co)rep(j,co){ cin>>d[i][j]; }
  rep(i,n)rep(j,n){
    int k; cin>>k; k--; 
    c[(i+j)%3][k]++;
  }
  int ans=inf;
  rep(i,co)rep(j,co)if(i!=j)rep(k,co)if(i!=k&&j!=k){
    int cur=0;
    rep(p,co){ cur += d[p][i]*c[0][p]; }
    rep(p,co){ cur += d[p][j]*c[1][p]; }
    rep(p,co){ cur += d[p][k]*c[2][p]; }
    ans = min(ans,cur);
  }
  cout << ans << endl;
  return 0;
}
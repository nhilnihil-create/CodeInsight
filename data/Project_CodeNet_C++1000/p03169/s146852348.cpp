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
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

vector<vector<vector<ld>>> dp(310, vector<vector<ld>>(310, vector<ld>(310,0)));
int n;

ld rec(int x, int y, int z){
  if(dp[x][y][z]!=0) return dp[x][y][z];
  if(x==0 && y==0 && z==0) return 0;
  ld tmp = 1.0;
  if(x>0){ tmp += rec(x-1,y+1,z)*(ld)x/n; }
  if(y>0){ tmp += rec(x,y-1,z+1)*(ld)y/n; }
  if(z>0){ tmp += rec(x,y,z-1)*(ld)z/n; }
  return dp[x][y][z] = tmp*n/(x+y+z);
}

int main(){
  cin >> n;
  vector<int> a(3,0);
  rep(i,n){
    int k; cin >> k; k--;
    a[k]++;
  }
  ld ans = rec(a[2],a[1],a[0]);
  cout << fixed << setprecision(10) << ans << ln;
  return 0;
}
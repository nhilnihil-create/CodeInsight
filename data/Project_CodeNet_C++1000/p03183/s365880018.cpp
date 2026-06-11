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
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=200010;
const ll mod=1e9+7;
/*
i番目とj番目のブロックどちらかを先に置くかを決められないか考える。
既に置かれている重さの合計をWとして、 
iの次にj : W+wi<=sj⇔W<=sj−wi
jの次にi : W+wj<=si⇔W<=si−wj
右辺を見比べて、
sj−wi>=si−wj⇔si+wi<=sj+wj
のとき、iの次にjをおいた方がが必ず得をする。
これは推移律を満たすのでs+wでソートしてdpすればよい。
*/

vector<vector<ll>> dp(1010, vector<ll>(20010));

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  rep(i,n){ cin>>a[i]>>b[i]>>c[i]; }
  vector<int> ord(n);
  rep(i,n){ ord[i]=i; } 
  sort(ord.begin(),ord.end(),[&](int x,int y){ return a[x]+b[x]<a[y]+b[y]; });  
  
  rep(i,n){
    int idx=ord[i];
    rep(j,b[idx]+1){ dp[i+1][j+a[idx]]=dp[i][j]+c[idx]; }
    rep(j,20001){ dp[i+1][j]=max(dp[i+1][j],dp[i][j]); }
  }
  ll ans=0;
  rep(i,20001){ ans = max(ans, dp[n][i]); }
  cout << ans << endl;
  return 0;
}
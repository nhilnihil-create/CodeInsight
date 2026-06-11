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
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

vector<ll> sum(1<<16,0);
vector<ll> dp(1<<16,-longinf);


//https://atcoder.jp/contests/dp/submissions/3947991

ll rec(int mask){
  if(dp[mask]!=-longinf){ return dp[mask]; }
  if(mask==0){ return 0; }
  int x=17;
  while(((1<<x)&mask)==0){x--;}
  mask^=(1<<x); 								//?? for  for-bun keisan?
  ll ret=-longinf;
  for(int i=mask;i>=0;--i){
    i&=mask;
//    ret=max(ret,sum[i]+rec(mask-i));
    ret=max(ret,sum[(1<<x)+i]+rec(mask-i));      //??
  }
//  return dp[mask]=ret;						//??
  return dp[mask^(1<<x)]=ret;
}

int main(){
  int n;
  cin >> n ;
  vector<vector<ll>> a(20, vector<ll>(20,0));
  rep(i,n)rep(j,n){ cin>>a[i][j]; }
  int mask=1<<n;
  rep(i,mask)rep(j,n)rep(k,j){
    if((i&(1<<j))&&(i&(1<<k))){ sum[i]+=a[j][k]; }
  }
  
  ll ans = rec(mask-1);
  cout << ans << endl;
  return 0;
}
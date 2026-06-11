#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
string s;
int h[200010];
int dp[1<<26];

int main(){
	cin>>s;
  int n=s.size();
  rep(i,n){
    h[i+1]=h[i]^(1LL<<(s[i]-'a'));
  }
  rep(i,1<<26)dp[i]=INF;
  dp[0]=0;
  rep(i,n){
    ll a=INF;
    rep(j,26){
      ll tmp=h[i+1]^(1LL<<j);
      minch(a,dp[tmp]+1);
    }
    minch(a,dp[h[i+1]]+1);
    minch(dp[h[i+1]],a);
  }
  if(h[n]==0)cout<<1<<endl;
  else cout<<dp[h[n]]<<endl;
	return 0;
}

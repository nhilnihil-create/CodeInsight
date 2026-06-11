#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll mod_pow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll N;
ll A[100010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  rep(i,N)cin>>A[i];

  ll suf=0;
  rep(i,N-1){
    (suf+=mod_pow(i+2,mod-2))%=mod;
  }
  ll prf=1;
  ll res=0;
  rep(i,N){
    res+=(prf+suf)*A[i]%mod;
    res%=mod;
    suf=(suf-mod_pow(N-i,mod-2)+mod)%mod;
    prf=(prf+mod_pow(i+2,mod-2))%mod;
  }

  rep(i,N)(res*=(i+1))%=mod;
  cout<<res<<endl;

  return 0;
}

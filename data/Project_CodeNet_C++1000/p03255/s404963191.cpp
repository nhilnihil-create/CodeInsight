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

ll N,X;
ll x[200010];
ll sum[200010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N>>X;
  rep(i,N)cin>>x[i];
  reverse(x,x+N);
  rep(i,N)sum[i+1]=sum[i]+x[i];
  __int128 res=1e22;
  repl(k,1,N+1){
    __int128 crt=0;
    for(ll i=0;i<N;i+=k){
      ll j=i/k;
      __int128 s=sum[min(N,i+k)]-sum[i];
      if(i==0)crt+=s*5;
      else crt+=s*(2*j+3);
    }
    __int128 add=X;
    add*=(N+k);
    minch(res,crt+add);
  }
  string ans;
  while(res>0){
    ans+=(char)('0'+res%10); res/=10;
  }
  reverse(all(ans));
  cout<<ans<<endl;

  return 0;
}

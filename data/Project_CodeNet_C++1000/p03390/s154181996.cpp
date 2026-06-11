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
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll Q,A,B;

int main(){
  cin>>Q;
  while(Q--){
    cin>>A>>B;
    if(A==B){
      cout<<(A-1)*2<<endl;
      continue;
    }
    ll p=A*B;
    ll lb=1,ub=1e9;
    while(ub-lb>1){
      ll mid=(lb+ub)/2;
      if(mid*mid<p)lb=mid;
      else ub=mid;
    }
    ll c=lb;
    if(c*(c+1)>=p){
      cout<<c*2-2<<endl;
    }else{
      cout<<c*2-1<<endl;
    }
  }
  return 0;
}

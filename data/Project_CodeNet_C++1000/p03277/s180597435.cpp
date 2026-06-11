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

struct BIT{
  int n;
  vector<ll> bit;
  BIT(int size):n(size),bit(size+1,0){}

  ll sum(int i){
    ll s=0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }

  void add(int i,ll v){
    if(i==0)return ;
    while(i<=n){
      bit[i]+=v;
      i+=i&-i;
    }
  }

  ll lower_bound(ll w){
    if(w<=0)return 0;
    ll x=0,r=1;
    while(r<n)r<<=1;
    for(ll k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }
};

ll n,m;
ll a[100010],b[100010],sum[100010];

bool ok(ll X){
  rep(i,n){
    if(a[i]<=X)b[i]=1;
    else b[i]=0;
  }
  rep(i,n){
    sum[i+1]=sum[i]+b[i];
  }
  const ll B=100010;
  BIT bit(2*B+10);
  ll cnt=0;
  rep(r,n+1){
    cnt+=bit.sum(2*sum[r]-r-1+B);
    bit.add(2*sum[r]-r+B,1);
  }
  return cnt>=m;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  rep(i,n)cin>>a[i];
  m=(n*(n+1)/2)/2+1;

  ll lb=0,ub=1e9;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(ok(mid))ub=mid;
    else lb=mid;
  }
  cout<<ub<<endl;

  return 0;
}

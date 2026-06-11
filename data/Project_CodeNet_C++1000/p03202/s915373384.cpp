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

bool add(map<int,int>& a, int d, int b){
  for(int j=d;j>=0;j--){
    a[j]++;
    if(a[j]==b){
      if(j==0) return false;
      a[j]=0;
    }else{
      break;
    }
  }
  return true;
}

int n;
int a[200010];

bool ok(int X){
  if(X==1){
    rep(i,n-1){
      if(a[i]>=a[i+1])return false;
    }
    return true;
  }
  map<int,int> crt;
  repl(i,1,n){
    if(a[i-1]>=a[i]){
      while(crt.lower_bound(a[i])!=crt.end()){
        crt.erase(crt.lower_bound(a[i]));
      }
      if(!add(crt,a[i]-1,X))return false;
    }
  }

  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  int lb=0,ub=n+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(ok(mid)) ub=mid;
    else lb=mid;
  }
  cout<<ub<<endl;

  return 0;
}

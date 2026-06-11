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

ll h,w,n;
ll x[200010],y[200010];
vector<ll> ys[200010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>w>>h>>n;
  rep(i,n){
    cin>>x[i]>>y[i];
    x[i]--; y[i]--;
    ys[x[i]].push_back(y[i]);
  }
  rep(j,w)sort(all(ys[j]));

  ll res=w,crt=1;
  rep(j,w-1){
    if(ys[j+1].size()==0){
      crt++; continue;
    }else{
      ll mny=ys[j+1][0];
      if(mny==crt)continue;
      if(mny<crt){
        res=j+1;
        break;
      }
      crt++;
    }
  }
  cout<<res<<endl;

  return 0;
}

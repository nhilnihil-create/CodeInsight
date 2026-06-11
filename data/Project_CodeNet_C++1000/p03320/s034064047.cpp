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

ll K;
vector<ll> v,ans;
bool dame[100000];

ll f(ll n){
  ll res=0;
  while(n>0){
    res+=n%10;
    n/=10;
  }
  return res;
}

int main(){
  repl(a,1,1001)repl(j,1,16){
    ll num=a*pow(10,j)-1;
    if(num>1e15)continue;
    v.push_back(num);
  }
  repl(i,1,10)v.push_back(i);
  sort(all(v));
  uni(v);
  rep(i,v.size())repl(j,i+1,v.size()){
    if(v[i]*f(v[j])>v[j]*f(v[i])){
      dame[i]=true;
      break;
    }
  }
  rep(i,v.size())if(!dame[i])ans.push_back(v[i]);
  cin>>K;
  rep(i,K){
    cout<<ans[i]<<endl;
  }

  return 0;
}

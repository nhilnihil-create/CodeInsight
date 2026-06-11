//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
#define mp make_pair
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

ll n,ans;

void bfs(ll x){
  if(x!=0&&x<=n){
    ll k=x,a=0,b=0,c=0;
    while(k!=0){
      if(k%10==3){
        a++;
      }
      else if(k%10==5){
        b++;
      }
      else if(k%10==7){
        c++;
      }
      k/=10;
    }
    if(a*b*c>0){
      ans++;
    }
  }
  if(x<=n){
    rep(i,3){
      bfs(10*x+3+2*i);
    }
  }
}

int main(){
  ans=0;
  cin >> n;
  bfs(0);
  cout << ans << endl;
}
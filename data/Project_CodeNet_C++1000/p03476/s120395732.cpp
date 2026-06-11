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
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll Q;
  cin >> Q;
  vector<bool> prime(100001,1);
  prime[0]=prime[1]=0;
  rep(i,100001){
    if(prime[i]==1){
      ll k=2*i;
      while(k<=100000){
        prime[k]=0;
        k+=i;
      }
    }
    else{
      continue;
    }
  }
  vl dp(100001,0);
  for(ll i=3;i<=100000;i+=2){
    dp[i]=dp[i-2];
    if(prime[i]==1&&prime[(i+1)/2]==1){
      dp[i]++;
    }
  }
  rep(t,Q){
    ll l,r;
    cin >> l >> r;
    if(l!=1)
    l-=2;
    cout << dp[r]-dp[l] << endl;
  }
}
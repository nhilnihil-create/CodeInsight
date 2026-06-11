#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=acos(-1);
const ll INF=1e18;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

vl memo(100001,-1);

ll dfs(ll x){
  if(memo[x]!=-1){
    return memo[x];
  }
  if(x==0){
    return 0;
  }
  if(x==1||x==6||x==9){
    memo[x]=1;
    return 1;
  }
  ll a=6,b=9;
  ll t=x;
  while(x>=a){
    t=min(dfs(x-a)+1,t);
    a*=6;
  }
  while(x>=b){
    t=min(dfs(x-b)+1,t);
    b*=9;
  }
  memo[x]=t;
  return t;
}

int main() {
  ll n;
  cin >> n;
  ll x=dfs(n);
  cout << x << endl;
}
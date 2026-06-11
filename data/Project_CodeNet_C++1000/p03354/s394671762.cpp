#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

vector<ll> par(100000);
vector<ll> ran(100000);
void init(ll n){
  rep(i,n){
    par.at(i)=i;
    ran.at(i)=0;
  }
}
ll find(ll x){
  if(par.at(x)==x){
    return x;
  }else{
    return par.at(x)=find(par.at(x));
  }
}
void unite(ll x,ll y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(ran.at(x)<ran.at(y)){
    par.at(x)=y;
  }else{
    par.at(y)=x;
    if(ran.at(x)==ran.at(y)) ran.at(x)++;
  }
}

int main(){
  ll N,M,ans=0;
  cin >> N >> M;
  vector<ll> P(N);
  rep(i,N){
    cin >> P.at(i);
    P.at(i)--;
  }
  init(N);
  rep(i,M){
    ll x,y;
    cin >> x >> y;
    x--;
    y--;
    unite(x,y);
  }
  rep(i,N){
    if(find(i)==find(P.at(i))){
      ans++;
    }
  }
  cout << ans << endl;
}
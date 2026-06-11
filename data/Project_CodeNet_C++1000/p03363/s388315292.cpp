#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e15+4;
const int Nmax=2e5+1;
const int Nd=61;
ll dfs[3003][3003][4];
ll  v[3003][3003];


int main(){
  int n;cin>>n;
  vector<int> a(n);
  vector<ll> sumA(n+1,0);// a[i-1]までの和
  map<ll,ll> m;
  m[0]++;
  rep(i,n){
    cin>>a[i];
    sumA[i+1]=sumA[i]+a[i];
    m[sumA[i+1]]++;
  }
  ll ans=0;
  for(auto mi: m){
    ll j=mi.second;
    //cout<<mi.first<<" "<<mi.second<<endl;
    ans+=j*(j-1)/2;
  }
  cout<<ans<<endl;
  return 0;


}

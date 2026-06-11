#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<n; ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using mii = map<int,int>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
using ti3 = tuple<int,int,int>;

int main(){
  ll n,m,x; cin>>n>>m>>x;
  vi a(m);
  REP(i,m) cin>>a[i];
  ll cost0=0,cost1=0;
  REP(i,m){
    if(a[i]<x) cost0+=1;
    else cost1+=1; 
  }
  cout<<min(cost0,cost1)<<endl;
}
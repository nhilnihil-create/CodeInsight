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
  ll s; cin>>s;
  vi a(1100000,0);
  REP(i,1100000){
    if(a[s]==0){
      a[s]=1;
      if(s%2==0) s=s/2;
      else s=3*s+1;
    } else{
      cout<<i+1<<endl;
      return 0;
    }
  }
}
#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SIZE(a) int((a).size())
const int INF=INT_MAX;
vvll con(15,vll(15,-1));//con[i][j]=人iが人jを正直/不親切と思っている

int main(){
  int n,m;
  cin>>n>>m;
  ll x[n],y[n],z[n],tmp=0;
  REP(i,n){
    cin>>x[i]>>y[i]>>z[i];
  }
  REP(i,1<<3){
    ll sum=0;vll all(n,0);
    bitset<3> bit(i);
    REP(j,n){
      if(bit.test(0)){all[j]+=x[j];}
      else{all[j]-=x[j];}
      if(bit.test(1)){all[j]+=y[j];}
      else{all[j]-=y[j];}
      if(bit.test(2)){all[j]+=z[j];}
      else{all[j]-=z[j];}
    }
    sort(all.begin(),all.end());reverse(all.begin(),all.end());
    REP(j,m){
      sum+=all[j];
    }
    tmp=max(sum,tmp);
  }
  cout<<tmp<<endl;
}
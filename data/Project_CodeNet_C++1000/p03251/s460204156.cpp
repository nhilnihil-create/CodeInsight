#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(a) int((a).size();
const int INF=INT_MAX;
int main(){
  ll n,m,x,y;
  cin>>n>>m>>x>>y;
  vll xx(n),yy(m);
  rep(i,0,n){cin>>xx[i];}
  rep(i,0,m){cin>>yy[i];}
  sort(xx.begin(),xx.end());
  sort(yy.begin(),yy.end());
  bool ok=false;
  rep(i,x+1,y+1){
    if(i>xx[n-1]&&yy[0]>=i){ok=true;break;}
  }
  if(ok){cout<<"No War"<<endl;}
  else{cout<<"War"<<endl;}
}
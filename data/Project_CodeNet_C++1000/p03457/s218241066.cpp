#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main() {
  int n;
  cin>>n;
  vector<ll> t(n),x(n),y(n);
  ll tp=0,xp=0,yp=0;
  rep(i,n){
    cin>>t[i]>>x[i]>>y[i];
    if(i==0){
      if(t[i]<x[i]+y[i]){
        cout<<"No"<<endl;
        return 0;
      }
      tp=t[i]; xp=x[i]; yp=y[i];
      continue;
    }
    if(t[i]-tp<abs(x[i]-xp)+abs(y[i]-yp)){
      cout<<"No"<<endl;
      return 0;
    }
    if((t[i]-tp)%2!=(abs(x[i]-xp)+abs(y[i]-yp))%2){
      cout<<"No"<<endl;
      return 0;
    }
    tp=t[i]; xp=x[i]; yp=y[i];
  }
  cout<<"Yes"<<endl;
}
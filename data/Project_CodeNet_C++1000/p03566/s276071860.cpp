#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <bits/stdc++.h> 
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

double v[200020];

int main(){
  rep(i,200020)v[i]=longinf;
  int n;
  cin >> n;
  pair<double,pair<double,double>> p[n];
  double t=0;
  rep(i,n){
    double x;
    cin >> x;
    double s=t;
    double e=t+x;
    t+=x;
    p[i].second.first=s;
    p[i].second.second=e;
  }
  rep(i,n)cin >> p[i].first;
  rep(i,n){
    rep(j,2*t+1){
      if(p[i].second.first<=0.5*j && 0.5*j<=p[i].second.second){
        v[j]=min(v[j],p[i].first);
      }
    }
  }
  rep(i,n){
    rep(j,2*t+1){
      v[j]=min(v[j],p[i].first+min(abs(0.5*j-p[i].second.first),abs(0.5*j-p[i].second.second)));
    }
  }
  rep(j,2*t+1)v[j]=min(v[j],-0.5*j+t);
  rep(j,2*t+1)v[j]=min(v[j],0.5*(double)j);
  double ans=0.0;
  rep(i,2*t){
    ans+=(v[i]+v[i+1])/2.0;
  }
  cout << setprecision(12) << ans/2.0 << endl;
return 0;}
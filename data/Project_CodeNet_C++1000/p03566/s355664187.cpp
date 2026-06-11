#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N;
  cin>>N;
  int t[N+2],v[N+2];
  t[0]=0;
  v[0]=0;
  REP(i,N){
    int ti;
    cin>>ti;
    t[i+1]=t[i]+ti;
  }
  REP(i,N)cin>>v[i+1];
  t[N+1]=t[N];
  v[N+1]=0;
  double v_max[t[N+1]*2+1];
  FOR(i,1,N+1){
    FOR(ti,t[i-1]*2,t[i]*2+1)v_max[ti]=v[i];
  }
  FOR(i,0,N+1){
    FOR(ti,t[i]*2,t[N+1]*2+1)v_max[ti]=min(v_max[ti],0.5*(ti-t[i]*2)+v[i]);
  }
  FOR(i,1,N+2){
    FOR(ti,0,t[i-1]*2+1)v_max[ti]=min(v_max[ti],0.5*(t[i-1]*2-ti)+v[i]);
  }
  double ans=0;
  REP(ti,t[N+1]*2+1)ans+=(v_max[ti]+v_max[ti+1])*0.25;
  cout<<fixed<<setprecision(3)<<ans<<endl;
  // REP(i,t[N+1]*2+1)cerr<<fixed<<setprecision(1)<<0.5*i<<": "<<v_max[i]<<endl;
  return 0;
}

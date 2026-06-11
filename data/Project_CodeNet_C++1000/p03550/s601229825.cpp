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
int absi(int a,int b){
  return max(a-b,b-a);
}

int main(){
  int N,Z,W;
  cin>>N>>Z>>W;
  int a[N];
  REP(i,N)cin>>a[i];
  int ans=0;
  ans=max(ans,absi(a[N-1],W));
  if(N>1)ans=max(ans,absi(a[N-2],a[N-1]));
  cout<<ans<<endl;
  return 0;
}
